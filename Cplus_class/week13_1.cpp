#include <iostream>
using namespace std;
template <class T>
class point {
	T x;
	T y;
public:
	point(T xval, T yval)
	{
		x = xval; y = yval;
	}
	T get_x() { return(x); }
};

int main()
{
	point<int> ip(10, 20);
	point<double> dp(10.12, 20.34);
	cout << ip.get_x() << endl;
	cout << dp.get_x() << endl;
	return 0;
}