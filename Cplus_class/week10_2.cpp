#include <iostream>
using namespace std;

class shape {
public:
	virtual void draw() {
		cout << "shape draw \n";
	}
	virtual void rotate(int i) {
		cout << "shape rotate : " << i << endl;
	}
};

class circle : public shape {
public:
	void draw() {
		cout << "circle draw\n";
	}
	void rotate(int i) {
		cout << "circle rotate : " << i << endl;
	}
};

class triangle : public shape {
public:
	void draw() {
		cout << "triangle draw\n";
	}
	void rotate(int i) {
		cout << "triangle rotate : " << i << endl;
	}
};

class rectangle : public shape {
public:
	void draw() {
		cout << "rectangle draw\n";
	}
	void rotate(int i) {
		cout << "rectangle rotate : " << i << endl;
	}
};

int main() {
	shape* shape_vec[3];
	circle circle1;
	triangle triangle1;
	rectangle rectangle1;
	shape_vec[0] = &circle1;
	shape_vec[1] = &triangle1;
	shape_vec[2] = &rectangle1;
	for (int i = 0; i < 3; i++) {
		cout << "shape: " << i << endl;
		shape_vec[i]->draw();
		shape_vec[i]->rotate(45);
		cout << "------------------ " << endl;

	}
	return 0;
}