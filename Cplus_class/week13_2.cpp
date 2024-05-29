#include <iostream>
using namespace std;
template <class T>
class point {
	T x;
	T y;
public:
	point(T xval, T yval) { x = xval; y = yval; }
	T get_x();
	void put_x(T xval);
};
template <class T>
T point<T>::get_x() {
	return(x);
}

template <class T>
void point<T>::put_x(T xval) {
	x = xval;
}
int main()
{
	point<int> ip(10, 20);
	point<double> dp(10.12, 20.34);

	ip.put_x(15);
	dp.put_x(15.12);

	cout << ip.get_x() << endl;
	cout << dp.get_x() << endl;
	return 0;
}