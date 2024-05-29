#include <iostream>
using namespace std;
template <class T1, class T2>
class point {
	T1 x;
	T2 y;
public:
	point(T1 xval, T2 yval)
	{
		x = xval; y = yval;
	}
	T1 get_x() { return(x); }
	T2 get_y() { return(y); }
};

int main()
{
	point<int, double> p1(1, 2.34);
	/*point<double> dp(10.12, 20.34);*/
	cout << p1.get_x() << endl;
	cout << p1.get_y() << endl;
	return 0;
}