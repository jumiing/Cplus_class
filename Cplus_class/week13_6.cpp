#include <iostream>
using namespace std;

template <typename T> // �Լ� ���ø� ����
T myMax(T x, T y)
{
	return(x > y) ? x : y;
}

int main() {
	int j = myMax(1, 0);
	cout << "max int = " << j << endl;

	double f = myMax(2.0, 3.2);
	cout << "max float = " << f << endl;

	return 0;
}