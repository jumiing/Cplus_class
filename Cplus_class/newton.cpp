#include <iostream>
#include <math.h>

//�Լ��� ����ȭ�� Ŭ���� F
class F {
	double* f;
	int maxdegree;

public:
	//Ŭ������ ������ �� �Ҹ��� ����
	F() : f(NULL), maxdegree(NULL) {}
	F(int degree, double* values) : maxdegree(degree) {
		f = new double[maxdegree + 1];
		for (int i = 0; i <= maxdegree; ++i) {
			f[i] = values[i];
		}
	}
	~F() { delete[] f; }
	//F Ŭ������ ���� ������ �ùٸ��� �ϱ� ���� ������ ������
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

	//�Լ��� x���� �Է��ϸ� ��� y���� ��ȯ�ϴ� �޼ҵ�
	double y(double x) {
		double y = f[0];
		for (int i = 1; i <= maxdegree; i++) {
			y += f[i] * pow(x, i);
		}
		return y;
	}

	//�Լ��� �̺��Ͽ� F ���·� ��ȯ
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

//������ �Լ� f�� �ʱⰪ�� �����ϸ� ���� �޼ҵ�� �ظ� ã���ִ� �Լ�
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

//y�� �ּ��� �ذ��� �Ǵ� ������ x�� ���ϱ� ���� ����� �����ϴ� �Լ�
double findMinX(F& f) {
	F df = f.df();
	int degree = df.getDegree();
	double* xs = new double[degree]; //�ذ��� ������ x���� ������ �� �迭
	xs[0] = newtonsMethod(df, -99999999.0);
	double post_x = xs[0];
	double front = df.y(post_x + 1);
	double back = df.y(post_x - 1);
	std::cout << "first postX is :" << post_x << std::endl;
	for (int i = 1; i < degree; i++) {
		while (!((front > 0 && back < 0) || (front < 0 && back>0))) {//ó���� ���� �ؿ��� �յ� ��ȣ�� �ٲ�� x���� ã�� ������ �����ϸ� ���� �ʱⰪ �ĺ� Ž��
			post_x += 1;
			front = df.y(post_x + 1);
			back = df.y(post_x - 1);
			std::cout << "postX is :" << post_x << "and y is " << df.y(post_x) << std::endl;

		}
		xs[i] = newtonsMethod(df, post_x);
		std::cout << "xs " << i << " is :" << xs[i];
	}
	//���� x���� �� y���� �ּҰ� �Ǵ� x ���ϱ�
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