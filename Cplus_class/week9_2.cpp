#include <iostream>

using namespace std;
class point {
	int x;
	int y;
public:
	void set_x(int xval) { x = xval; }
};

class color_point : protected point {
	int color;
public:
	void set_x_value(int xval) { set_x(xval); }
};

int main() {
	color_point cp;
	cp.set_x_value(10); // ����� protected�� �޾ұ� ������ ��� Ŭ������ public �Լ��� ��� �Ұ�
	return 0;
}