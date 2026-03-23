# include "Header.h"

int main() {
	using namespace std;
	setlocale(LC_ALL, "Rus");
	int num;

	cout << "~ Yo, hiii ~ " << endl;
	cout << "====== Выбор задачи (0 - выход) ====== \n";
	num = getNumber();
	while (num != 0 && (num < 1 || num>5)) {
		cout << "Нужна цифра 1-5!\n ";
		num = getNumber();
	}

	while (num != 0) {

		switch (num) {
		case 1:
			system("cls"); // очистка консоли
			cout << endl << "(^-^) ============  Задание 1  ============ (^-^)" << endl;
			cout << "\n";
			task_1();
			cout << endl;
			break;
		case 2:
			system("cls"); // очистка консоли
			cout << endl << "(^-^) ============  Задание 2  ============ (^-^)" << endl;
			cout << "\n";
			task_2();
			cout << endl;
			break;
		case 3:
			system("cls"); // очистка консоли
			cout << endl << "(^-^) ============  Задание 3  ============ (^-^)" << endl;
			cout << "\n";
			task_3();
			cout << endl;
			break;
		case 4:
			system("cls"); // очистка консоли
			cout << endl << "(^-^) ============  Задание 4  ============ (^-^)" << endl;
			cout << "\n";
			task_4();
			cout << endl;
			break;
		case 5:
			system("cls"); // очистка консоли
			cout << endl << "(^-^) ============  Задание 5  ============ (^-^)" << endl;
			cout << "\n";
			task_5();
			cout << endl;
			break;
		}
		cout << "====== Выбор задачи (0 - выход) ====== \n";
		num = getNumber();
		while (num != 0 && (num < 1 || num>5)) {
			cout << "Нужна цифра 1-5!\n";
			num = getNumber();
		}
	}
	system("cls"); // очистка консоли
	cout << endl << "(x-x) ============ конец проги ============ (x-x)" << endl;
	cout << endl << "byeee ~" << endl;
}
