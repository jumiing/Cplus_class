#include <iostream>
using namespace std;

class complex {
	double re, im;
public:
	complex(double r = 0, double i = 0) { re = r; im = i; }
	/*friend ostream& operator<<(ostream& s, complex z);*/
	ostream& operator<<(ostream& s);

};

//ostream& operator<<(ostream& s, complex z)
//{
//	return s << z.re << " + " << z.im << "i";
//}
ostream& complex::operator<<(ostream& s)
{
	return s << re << " + " << im << "i";
}

int main()
{
	complex com(1, 2);
	/*cout << com << endl;*/
	com << cout << endl; // com.operator<<(cout);
	return 0;
}