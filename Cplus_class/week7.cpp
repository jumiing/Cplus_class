#include <iostream>
using namespace std;

class name
{
	char* buf;
	int size;
public:
	name(const char* s) {//문자열 포인터로 인자를 받아와 buf에 저장
		size = strlen(s) + 1;
		buf = new char[size];
		strcpy_s(buf,size, s);
	}
	void setchar(int i, char c) { buf[i] = c; }//i번째 배열에 c를 넣기
	void show_data(void) {//버퍼 값에 저장된 내용을 name으로 출력
		cout << "name : " << buf << endl;
	}
};

int main() {
	name n1("david");
	name n2 = n1;
	n2.setchar(0, 'D');
	n1.show_data();
	n2.setchar(1, 'A');
	n2.show_data();

	return 0;
}