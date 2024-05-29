//연산자 중복의 필요성 보기
#include <iostream>
using namespace std;
class complex {
	double re, im;
public : 
	complex(double r = 0, double i = 0) {
		re = r;
		im = i;
	}
	void show_data() {
		cout << re << "+" << im << "i" << endl;
	}
	/*friend complex add(complex, complex);*/

	friend complex operator+(complex, complex);
};
//complex add(complex a1, complex b1) {
//	complex r;
//	r.re = a1.re + b1.re;
//	r.im = a1.im + b1.im;
//	return r;
//}

complex operator+(complex a1, complex b1) {
	complex r;
	r.re = a1.re + b1.re;
	r.im = a1.im + b1.im;
	return r;
}
int main() {
	complex a(1, 1), b(2, 2), c(3, 3), d;
	/*d = add(add(a, b),c);*/
	d = a + b + c; //더 편리하게 사용 가능
	d.show_data();
	return 0;
}