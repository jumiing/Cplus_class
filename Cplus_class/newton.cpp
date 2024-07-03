#include <iostream>
#include <math.h>

//함수를 구조화한 클래스 F
class F {
	double* f;
	int maxdegree;

public:
	//클래스의 생성자 및 소멸자 정의
	F() : f(NULL), maxdegree(NULL) {}
	F(int degree, double* values) : maxdegree(degree) {
		f = new double[maxdegree + 1];
		for (int i = 0; i <= maxdegree; ++i) {
			f[i] = values[i];
		}
	}
	~F() { delete[] f; }
	//F 클래스의 대입 연산을 올바르게 하기 위한 연산자 재정의
	F& operator=(const F& other) {
		if (this != &other) {
			delete[] f;
			maxdegree = other.maxdegree;
			f = new double[maxdegree + 1];
			for (int i = 0; i <= maxdegree; ++i) {
				f[i] = other.f[i];
			}
		}
		return *this;
	}

	int getDegree() { return maxdegree; }

	void setF() {
		std::cout << "max degree :";
		std::cin >> maxdegree;
		f = new double[maxdegree + 1];

		std::cout << "Enter " << maxdegree + 1 << " numbers (less degree first):" << std::endl;
		for (int i = 0; i <= maxdegree; ++i) {
			std::cin >> f[i];
		}

	}

	void printF() const {
		std::cout << "this F:" << std::endl;
		for (int i = 0; i <= maxdegree; ++i) {
			std::cout << f[i] << " ";
		}
		std::cout << std::endl;
	}

	//함수의 x값을 입력하면 결과 y값을 반환하는 메소드
	double y(double x) {
		double y = f[0];
		for (int i = 1; i <= maxdegree; i++) {
			y += f[i] * pow(x, i);
		}
		return y;
	}

	//함수를 미분하여 F 형태로 반환
	F df() {
		if (maxdegree == 0) {
			double* zero_coefficients = new double[1] {0};
			return F(0, zero_coefficients);
		}

		int new_degree = maxdegree - 1;
		double* new_coefficients = new double[new_degree + 1];

		for (int i = 1; i <= maxdegree; ++i) {
			new_coefficients[i - 1] = i * f[i];
		}

		return F(new_degree, new_coefficients);
	}
};

//연산할 함수 f와 초기값을 대입하면 뉴턴 메소드로 해를 찾아주는 함수
double newtonsMethod(F& f, double initialGuess) {
	double x = initialGuess;
	F df1 = f.df();
	F df2 = df1.df();
	for (int i = 0; i < 100; ++i) {
		double fx = df1.y(x);
		double dfx = df2.y(x);
		if (fabs(dfx) < 1e-6) break; 
		double x_next = x - fx / dfx;
		if (fabs(x_next - x) < 1e-6) break;
		x = x_next;
	}
	return x;
}

//y가 최소인 극값이 되는 지점의 x를 구하기 위한 기능을 수행하는 함수
double findMinX(F& f) {
	F df = f.df();
	int degree = df.getDegree();
	double* xs = new double[degree]; //극값을 가지는 x들을 저장해 둘 배열
	xs[0] = newtonsMethod(df, -99999999.0);
	double post_x = xs[0];
	double front = df.y(post_x + 1);
	double back = df.y(post_x - 1);
	std::cout << "first postX is :" << post_x << std::endl;
	for (int i = 1; i < degree; i++) {
		while (!((front > 0 && back < 0) || (front < 0 && back>0))) {//처음에 구한 해에서 앞뒤 부호가 바뀌는 x값을 찾을 때까지 전진하며 다음 초기값 후보 탐색
			post_x += 1;
			front = df.y(post_x + 1);
			back = df.y(post_x - 1);
			std::cout << "postX is :" << post_x << "and y is " << df.y(post_x) << std::endl;

		}
		xs[i] = newtonsMethod(df, post_x);
		std::cout << "xs " << i << " is :" << xs[i];
	}
	//구한 x값들 중 y값이 최소가 되는 x 구하기
	double min = xs[0];
	for (int i = 0; i < degree; i++) {
		if (df.y(xs[i]) < df.y(min)) {
			min = xs[i];
		}
	}
	std::cout << "min is :" << min << "and y is " << df.y(min) << std::endl;
	return min;
}

int main() {
	F f;
	f.setF();
	findMinX(f);
	return 0;
}