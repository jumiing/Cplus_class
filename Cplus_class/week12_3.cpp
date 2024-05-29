//값에 의한 반환 문제점 해결
#include <iostream>
using namespace std;
class complex {
	double re, im;
public:
	complex(double r = 0, double i = 0) {
		re = r;
		im = i;
	}
	void show_data() {
		cout << re << "+" << im << "i" << endl;
	}
	friend complex& operator++(complex&);
};

complex& operator++(complex& a1) {
	a1.re = a1.re + 1;
	a1.im = a1.im + 1;
	return a1;
}
int main() {
	complex a(1, 1);
	++(++a);
	a.show_data();
	return 0;
}