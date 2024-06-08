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

	F df() const {
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

double newtonsMethod(F& f, double initialGuess) {
	double x = initialGuess;
	F df1 = f.df();
	F df2 = df1.df();
	for (int i = 0; i < 100; ++i) {
		double fx = df1.y(x);
		double dfx = df2.y(x);
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
	double root = newtonsMethod(f, 0);
	std::cout << "Root :" << root << std::endl;
	return 0;
}