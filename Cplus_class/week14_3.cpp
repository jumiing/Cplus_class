#include <fstream>
using namespace std;

int main()
{
	ofstream out;
	out.open("C:inout_file.txt", ios::app);//���� �ø��� ���� ���� �ٿ��ֱ�
	out << "Kyonggi" << endl;
	out.close();
	return 0;
}