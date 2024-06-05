//#include <fstream>
//
//using namespace std;
//
//int main()
//{
//	ofstream out;
//	out.open("C:inout_file.txt");// D드라이브 없으면 C에서는 잘 작동하지 않음
//	out << "Kyonggi" << endl;
//	out.close();
//	return 0;
//}

/////// 파일 읽기 코드
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