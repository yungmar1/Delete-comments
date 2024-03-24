/*


****************************************
			 TEST COMMENT
****************************************


*/
#include <iostream>
#include <fstream>

using namespace std;

//прототип функции удаления комментариев
void deleteComments(ifstream& in, ofstream& out);

int main() {
	setlocale(LC_ALL, "ru");
	//создание объектов потока ввода in и вывода out
	ifstream in;
	ofstream out;
	//объект in подключается к текущему файлу task_2.cpp
	in.open("Delete_comments.cpp");
	out.open("WithoutComments.cpp");

	//проверка корректности открытия файла
	if (!in) {
		cout << "Ошибка открытия файла!";
	}
	deleteComments(in, out);
	in.close();
	out.close();
	cout << "Проверка: " << 16 / 2 << " = " << 4 * 2 << ".\n\n";

	return 0;
}
/*


****************************************
			 TEST COMMENT
****************************************


*/

//функция удаления комментариев
void deleteComments(ifstream& in, ofstream& out) {
	//удаление флага skipws, чтобы сохранить пробелы и табуляцию
	in.unsetf(ios::skipws);
	char ch = '\0', tmp = '\0';
	bool flag = false;

	while (!in.eof()) {
		in >> ch;
		//проверка открывающего комментария
		if (ch == '/') {
			in >> tmp;
			if (tmp == '*') {
				in >> ch;
				flag = true;
			}
			else {
				//возвращение символа обратно в поток
				in.putback(tmp);
			}
			tmp = '\0';
		}
		//нахождение внутри комментария
		if (flag) {
			//проверка закрывающего комментария
			if (ch == '*') {
				in >> tmp;
				if (tmp == '/') {
					//ввод и последующее удаление символа переноса строки
					in >> tmp;
					flag = false;
					tmp = '\0';
					ch = '\0';

				}
			}
		}
		//вывод символа в файл и на консоль
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