#include <iostream>
using namespace std;
template <class T>
class point {
	T x;
	T y;
public:
	point(T xval = 0, T yval = 0)
	{
		x = xval; y = yval;
	}
	T get_x() { return(x); }
	point& operator++() { ++x; return *this; }
};

int main()
{
	point<int> ip(10, 20);
	point<double> dp(10.12, 20.34);
	++ip;
	cout << ip.get_x() << endl;
	++dp;
	cout << dp.get_x() << endl;
	return 0;
}
