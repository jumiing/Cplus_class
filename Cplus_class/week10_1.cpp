#include <iostream>

using namespace std;
class point {
	int x;
	int y;

public:
	point(int xval, int yval) {
		x = xval;
		y = yval;
	}

	int get_x() {
		return x;
	}
};

class color_point : public point {
	int color;
public:
	color_point(int xval, int yval, int color_value) : point(xval, yval) {
		color = color_value;
	}

	int get_color() {
		return color;
	}
};

int main() {
	/*point p(10, 20), * pp;*/
	color_point cp(10, 20, 30), * cpp;
	point* pp;
	pp = &cp;
	//cpp = &p; //유도클래스 포인터로 기반 클래스를 가르키는 것은 불가능
	cout << pp->get_x() << endl; //기반 클래스로 접근 시 유도 클래스 내에 있는 함수는 사용 불가
}