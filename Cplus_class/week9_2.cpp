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
	cp.set_x_value(10); // 상속을 protected로 받았기 때문에 기반 클래스의 public 함수도 사용 불가
	return 0;
}