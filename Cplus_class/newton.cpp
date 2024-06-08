#include <iostream>
#include <math.h>

class F {
	double* f;
	int maxdegree;

public :
	F() : f(NULL), maxdegree(NULL) {}
	F(int degree, double* values) : maxdegree(degree) {
		f = new double[maxdegree + 1];
		for (int i = 0; i <= maxdegree; ++i) {
			f[i] = values[i];
		}
	}
	~F() { delete[] f; }

	void setF() {
		std::cout << "max degree :";
		std::cin >> maxdegree;
		f = new double[maxdegree + 1];

		std::cout << "Enter " << maxdegree+1 << " numbers (less degree first):" << std::endl;
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

	double y(int x) {
		double y = f[0];
		for (int i = 1; i <= maxdegree; i++) {
			y += f[i] * pow(x, i);
		}
		return y;
	}

	F df(int n) {
		if (n > maxdegree) {
			// 미분 횟수가 다항식의 차수보다 클 경우, 모든 계수가 0인 함수 반환
			double* zero_coefficients = new double[1] {0};
			return F(0, zero_coefficients);
		}

		int new_degree = maxdegree - n;
		double* new_coefficients = new double[new_degree + 1];

		// 원본 다항식을 복사한 임시 배열
		double* temp = new double[maxdegree + 1];
		for (int i = 0; i <= maxdegree; ++i) {
			temp[i] = f[i];
		}

		for (int k = 0; k < n; ++k) {
			for (int i = 0; i <= maxdegree - k - 1; ++i) {
				temp[i] = (i + 1) * temp[i + 1];
			}
		}

		for (int i = 0; i <= new_degree; ++i) {
			new_coefficients[i] = temp[i];
		}

		delete[] temp;

		return F(new_degree, new_coefficients);
	}
};

double newtonsMethod(F& f, double initialGuess) {
	double x = initialGuess;
	for (int i = 0; i < 100; ++i) {
		double fx = f.y(x);
		F df1 = f.df(1);
		/*std::cout << "df1 :" << std::endl;
		df1.printF();*/

		double dfx = df1.y(x);
		if (fabs(dfx) < 1e-12) break; // 0으로 나누기 방지
		double x_next = x - fx / dfx;
		if (fabs(x_next - x) < 1e-12) break; // 수렴 조건
		x = x_next;
	}
	return x;
}

int main() {
	F f;
	f.setF();
	f.printF();
	F df = f.df(1);
	double root = newtonsMethod(df, 0);
	std::cout << "Root :" << root << std::endl;
	return 0;
}