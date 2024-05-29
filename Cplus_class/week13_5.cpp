#include <iostream>
using namespace std;

int main() {
	int number;
	cout << "input number : ";
	cin >> number;

	//int x[number];//변수값으로 데이터 할당 불가
	int *x;
	x = new int[number];

	int i;
	for (i = 0; i < number; i++) x[i] = i;
	for (i = 0; i < number; i++) cout << "x[" << i << "]= " << x[i] << endl;

	return 0;
}