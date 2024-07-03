#include <iostream>
#include <math.h>
using namespace std;
class F {
	double* f;
	int maxdegree;
public:
	F() : f(NULL), maxdegree(NULL) {}
	F(int degree, double* values) : maxdegree(degree) {
		f = new double[maxdegree + 1];
		for (int i = 0; i <= maxdegree; ++i) {
			f[i] = values[i];
		}
	}
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

	void setF() {
		std::cout << "max degree :";
		std::cin >> maxdegree;
		f = new double[maxdegree + 1];

		std::cout << "Enter " << maxdegree + 1 << " numbers :" << std::endl;
		for (int i = maxdegree; i >=0; --i) {
			std::cin >> f[i];
		}

	}

	int getDegree() { return maxdegree; }

	double y(double x) {
		double y = f[0];
		for (int i = 1; i <= maxdegree; i++) {
			y += f[i] * pow(x, i);
		}
		return y;
	}

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
class FindMin : public F {
public: 
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
	double findMinX(F& f) {
		F df = f.df();
		int degree = df.getDegree();
		double* xs = new double[degree]; //�ذ��� ������ x���� ������ �� �迭
		xs[0] = newtonsMethod(df, -99999999.0);
		double post_x = xs[0];
		double front = df.y(post_x + 1);
		double back = df.y(post_x - 1);
		for (int i = 1; i < degree; i++) {
			while (!((front > 0 && back < 0) || (front < 0 && back>0))) {//ó���� ���� �ؿ��� �յ� ��ȣ�� �ٲ�� x���� ã�� ������ �����ϸ� ���� �ʱⰪ �ĺ� Ž��
				post_x += 1;
				front = df.y(post_x + 1);
				back = df.y(post_x - 1);
			}
			xs[i] = newtonsMethod(df, post_x);
		}
		cout << "f'(x) = 0�� �����ϴ� x��" << endl;
		for (int i = 0; i < degree; i++) {
			cout << i + 1 << ". x = " << xs[i] << "   -> f(x) = " << f.y(xs[i]) << endl;
		}
		//���� x���� �� y���� �ּҰ� �Ǵ� x ���ϱ�
		double min = xs[0];
		for (int i = 0; i < degree; i++) {
			if (df.y(xs[i]) < df.y(min)) {
				min = xs[i];
			}
		}
		cout << "���� ���� y�� �����ϴ� x = " << min << endl;
		return min;
	}
};

int main() {

	F f;
	f.setF();
	FindMin q1;
	q1.findMinX(f);
	return 0;
}