#include <iostream>
using namespace std;

template <class T>
class Vector {
	T* data;
public:
	Vector(int);
	~Vector() { delete[] data; }
	T& operator[](int i) { return data[i]; }
};

template <class T>
Vector<T>::Vector(int n) {
	data = new T[n];
}

int main() {
	Vector<int> x(5);
	int i;
	for (i = 0; i < 5; i++) x[i] = i;
	for (i = 0; i < 5; i++) cout << x[i] << " ";
	cout << endl;

	Vector<float> y(5);
	for (i = 0; i < 5; i++) y[i] = (float)(i + 0.5);
	for (i = 0; i < 5; i++) cout << y[i] << " ";
	cout << endl;
	return 0;
}