//#include <fstream>
//
//using namespace std;
//
//int main()
//{
//	ofstream out;
//	out.open("C:inout_file.txt");// D����̺� ������ C������ �� �۵����� ����
//	out << "Kyonggi" << endl;
//	out.close();
//	return 0;
//}

/////// ���� �б� �ڵ�
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	char c[20];
	ifstream in;
	in.open("C:inout_file.txt");
	if (!in.fail()) {
		in >> c;
		cout << "inout file value = " << c << endl;
		in.close();
	}

	return 0;
}