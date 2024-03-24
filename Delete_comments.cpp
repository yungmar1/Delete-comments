/*


****************************************
			 TEST COMMENT
****************************************


*/
#include <iostream>
#include <fstream>

using namespace std;

//�������� ������� �������� ������������
void deleteComments(ifstream& in, ofstream& out);

int main() {
	setlocale(LC_ALL, "ru");
	//�������� �������� ������ ����� in � ������ out
	ifstream in;
	ofstream out;
	//������ in ������������ � �������� ����� task_2.cpp
	in.open("Delete_comments.cpp");
	out.open("WithoutComments.cpp");

	//�������� ������������ �������� �����
	if (!in) {
		cout << "������ �������� �����!";
	}
	deleteComments(in, out);
	in.close();
	out.close();
	cout << "��������: " << 16 / 2 << " = " << 4 * 2 << ".\n\n";

	return 0;
}
/*


****************************************
			 TEST COMMENT
****************************************


*/

//������� �������� ������������
void deleteComments(ifstream& in, ofstream& out) {
	//�������� ����� skipws, ����� ��������� ������� � ���������
	in.unsetf(ios::skipws);
	char ch = '\0', tmp = '\0';
	bool flag = false;

	while (!in.eof()) {
		in >> ch;
		//�������� ������������ �����������
		if (ch == '/') {
			in >> tmp;
			if (tmp == '*') {
				in >> ch;
				flag = true;
			}
			else {
				//����������� ������� ������� � �����
				in.putback(tmp);
			}
			tmp = '\0';
		}
		//���������� ������ �����������
		if (flag) {
			//�������� ������������ �����������
			if (ch == '*') {
				in >> tmp;
				if (tmp == '/') {
					//���� � ����������� �������� ������� �������� ������
					in >> tmp;
					flag = false;
					tmp = '\0';
					ch = '\0';

				}
			}
		}
		//����� ������� � ���� � �� �������
		if (!flag) {
			out << ch;
			cout << ch;
		}
	}
}
/*


****************************************
			 TEST COMMENT
****************************************


*/