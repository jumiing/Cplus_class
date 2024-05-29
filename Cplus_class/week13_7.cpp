#include <iostream>
using namespace std;

template <typename T>
int mySizeOf(T a)
{
	return sizeof(a);
}

int main()
{
	int i = 10;
	double f = 10.123;
	char str[] = "c++ language!";

	cout << mySizeOf(i) << endl;
	cout << mySizeOf(f) << endl;
	cout << mySizeOf(str) << endl;

	return 0;
}