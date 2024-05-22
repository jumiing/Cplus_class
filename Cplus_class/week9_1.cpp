#include <iostream>

using namespace std;
class point {
	int x;
	int y;
public : 
	void set_x(int xval) { x = xval; }
	void set_y(int yval) { y = yval; }
	int get_x() { return x; }
	int get_y() { return y; }
};

class color_point : public point {
	int color;
public:
	void set_color(int cval) { color = cval; }
	int get_color() {return color; }
};

int main() {
	color_point cp;
	cp.set_x(10);
	cout << cp.get_x() << endl;
	return 0;
}