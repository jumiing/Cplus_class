#include <iostream>
using namespace std;

class name
{
	char* buf;
	int size;
public:
	name(const char* s) {//���ڿ� �����ͷ� ���ڸ� �޾ƿ� buf�� ����
		size = strlen(s) + 1;
		buf = new char[size];
		strcpy_s(buf, size, s);
	}
	//�߰��� �κ� - �����ε�
	name(const name& x) {//���� ������ �̿��� ��ü ���ڸ� �޾ƿ�
		size = x.size;
		buf = new char[size];
		strcpy_s(buf,size, x.buf);
	}

	void setchar(int i, char c) { buf[i] = c; }//i��° �迭�� c�� �ֱ�
	void show_data(void) {//���� ���� ����� ������ name���� ���
		cout << "name : " << buf << endl;
	}
};

int main() {
	name n1("david");
	name n2 = n1;//n2(n1)
	n2.setchar(0, 'D');
	n1.show_data();
	//n2.setchar(1, 'A');
	n2.show_data();

	return 0;
}