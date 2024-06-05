#include <fstream>
using namespace std;

int main()
{
	ofstream out;
	out.open("C:inout_file.txt", ios::app);//실행 시마다 파일 끝에 붙여넣기
	out << "Kyonggi" << endl;
	out.close();
	return 0;
}