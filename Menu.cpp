# include "Header.h"

// ======================= ПРОВЕРКА ВВОДА =======================

// проверка ввода числа 
int getNumber() {
	using namespace std;
	int value;

	while (true) {
		cout << "Введите число: ";
		cin >> value;

		if (cin.fail()) {  // Если ввод не является числом
			cout << "Ошибка! Введите ЧИСЛО, а не буквы!" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			return value;
		}
	}
}

// проверка ввода строки
std::string getText() {
	using namespace std;
	string input;
	bool hasDigit;

	while (true) {
		hasDigit = false;
		cout << "Введите имя файла: ";
		getline(cin, input);

		// Проверка на пустую строку
		if (input.empty()) {
			cout << "Ошибка! Строка не может быть пустой!" << endl;
			continue;
		}

		for (int i = 0; i < input.length(); i++) {
			if (isdigit(input[i])) {  // если символ - цифра
				hasDigit = true;
				break;
			}
		}

		if (hasDigit) {
			cout << "Ошибка! В тексте не должно быть цифр!" << endl;
		}
		else {
			return input;  // цифр нет, возвращаем строку
		}
	}
}


// ======================= МЕНЮ ДЛЯ ВВОДА ВСЕХ СТРУКТУР =======================

// ввод двусвязного списка
void inputForDoublyLinkedList(DoublyLinkedList& DList) {
	using namespace std;
	int cnt, input, data;

	cout << "=== Заполнение двусвязного списка ===" << endl;

	cout << "Доступные способы заполнения списка:\n 1 - c консоли\n 2 - рандомно\n 3 - из файла" << endl;
	input = getNumber();

	while (input < 1 || input>3) {
		cout << "Ошибка! Введите цифру 1-3: ";
		input = getNumber();
	}

	switch (input) {
	case 1:
		cout << "\n===== Количество чисел ===== \n";
		cnt = getNumber();
		while (cnt < 0 || cnt == 0) {
			cout << "\nОшибка! Число должно быть натуральным!\n\n";
			cnt = getNumber();
		}
		for (int i = 0; i < cnt; i++) {
			data = getNumber();
			DList.pushBack(data);
		}
		break;
	case 2:
		srand(time(nullptr));

		cout << "\n===== Количество чисел ===== \n";

		cnt = getNumber();
		while (cnt < 0 || cnt == 0) {
			cout << "\nОшибка! Число должно быть натуральным!\n\n";
			cnt = getNumber();
		}

		for (int i = 0; i < cnt; i++) {
			data = rand() % 141 - 70;
			DList.pushBack(data);
		}
		break;
	case 3:
		int n;
		string filename;
		
		cout << "Введите имя файла: ";
		filename = getText();

		ifstream file(filename);

		if (!file.is_open()) {
			cout << "Ошибка открытия файла!";
			return;
		}
		else {
			file >> n;
			for (int i = 0; i < n; i++) {
				int data;
				file >> data;
				DList.pushBack(data);
			}
		}
	}

	DList.print();
}

// ввод двусвязного циклического списка
void inputForDoublyLinkedCyclicList(DoublyLinkedCyclicList& DList) {
	using namespace std;
	int cnt, input, data;

	cout << "==== Заполнение двусвязного циклического списка ====" << endl;

	cout << "Доступные способы заполнения списка:\n 1 - c консоли\n 2 - рандомно\n 3 - из файла" << endl;
	input = getNumber();

	while (input < 1 || input>3) {
		cout << "Ошибка! Введите цифру 1-3: ";
		input = getNumber();
	}

	switch (input) {
	case 1:
		cout << "\n===== Количество чисел ===== \n";
		cnt = getNumber();
		while (cnt < 0 || cnt == 0) {
			cout << "\nОшибка! Число должно быть натуральным!\n\n";
			cnt = getNumber();
		}
		for (int i = 0; i < cnt; i++) {
			data = getNumber();
			DList.pushBack(data);
		}
		break;
	case 2:
		srand(time(nullptr));

		cout << "\n===== Количество чисел ===== \n";

		cnt = getNumber();
		while (cnt < 0 || cnt == 0) {
			cout << "\nОшибка! Число должно быть натуральным!\n\n";
			cnt = getNumber();
		}

		for (int i = 0; i < cnt; i++) {
			data = rand() % 141 - 70;
			DList.pushBack(data);
		}
		break;
	case 3:
		int n;
		string filename;

		cout << "Введите имя файла: ";
		filename = getText();

		ifstream file(filename);

		if (!file.is_open()) {
			cout << "Ошибка открытия файла!";
			return;
		}
		else {
			file >> n;
			for (int i = 0; i < n; i++) {
				int data;
				file >> data;
				DList.pushBack(data);
			}
		}
	}

	DList.print();
}

// ввод односвязного циклического списка
void inputForCyclicList(CyclicList& DList) {
	using namespace std;
	int cnt, input, data;

	cout << "==== Заполнение односвязного циклического списка ====" << endl;

	cout << "Доступные способы заполнения списка:\n 1 - c консоли\n 2 - рандомно\n 3 - из файла" << endl;
	input = getNumber();

	while (input < 1 || input>3) {
		cout << "Ошибка! Нужна цифра 1-3!\n";
		input = getNumber();
	}

	switch (input) {
	case 1:
		cout << "===== Количество чисел ===== \n";
		cnt = getNumber();
		while (cnt < 0 || cnt == 0) {
			cout << "\nОшибка! Число должно быть натуральным!\n\n";
			cnt = getNumber();
		}
		for (int i = 0; i < cnt; i++) {
			data = getNumber();
			DList.pushBack(data);
		}
		break;
	case 2:
		srand(time(nullptr));

		cout << "\n===== Количество чисел ===== \n";

		cnt = getNumber();
		while (cnt < 0 || cnt == 0) {
			cout << "\nОшибка! Число должно быть натуральным!\n\n";
			cnt = getNumber();
		}

		for (int i = 0; i < cnt; i++) {
			data = rand() % 141 - 70;
			DList.pushBack(data);
		}
		break;
	case 3:
		int n;
		string filename;

		cout << "Введите имя файла: ";
		filename = getText();

		ifstream file(filename);

		if (!file.is_open()) {
			cout << "Ошибка открытия файла!";
			return;
		}
		else {
			file >> n;
			for (int i = 0; i < n; i++) {
				int data;
				file >> data;
				DList.pushBack(data);
			}
		}
	}

	DList.print();
}



// ======================= МЕНЮ ДЛЯ ВЫВОДА ВСЕХ СТРУКТУР =======================

// Вывод двусвязного циклического списка
void OutputForDoublyLinkedCyclicList(DoublyLinkedCyclicList& DList) {
	using namespace std;
	int cnt, input;

	cout << "\n\n=== Вывод двусвязного циклического списка ===" << endl;

	cout << "Доступные способы вывода списка:\n 1 - в консоль\n 2 - в файл" << endl;
	input = getNumber();

	while (input < 1 || input>2) {
		cout << "Ошибка! Нужна цифра 1 или 2!\n ";
		input = getNumber();
	}

	switch (input) {
	case 1:
		cout << endl;
		DList.print();
		cout << endl;
		break;
	case 2:
		DList.FromListToFile();
	}
}

// Вывод двусвязного списка
void OutputForDoublyLinkedList(DoublyLinkedList& DList) {
	using namespace std;
	int cnt, input;

	cout << "\n\n=== Вывод двусвязного списка ===" << endl;

	cout << "Доступные способы вывода списка:\n 1 - в консоль\n 2 - в файл" << endl;
	input = getNumber();

	while (input < 1 || input>2) {
		cout << "Ошибка! Нужна цифра 1 или 2!\n ";
		input = getNumber();
	}

	switch (input) {
	case 1:
		cout << endl;
		DList.print();
		cout << endl;
		break;
	case 2:
		DList.FromListToFile();
	}
}

// Вывод односвязного циклического списка
void OutputForCyclicList(CyclicList& DList) {
	using namespace std;
	int cnt, input;

	cout << "\n\n=== Вывод односвязного циклического списка ===" << endl;

	cout << "Доступные способы вывода списка:\n 1 - в консоль\n 2 - в файл" << endl;
	input = getNumber();

	while (input < 1 || input>2) {
		cout << "Ошибка! Нужна цифра 1 или 2!\n ";
		input = getNumber();
	}

	switch (input) {
	case 1:
		cout << endl;
		DList.print();
		cout << endl;
		break;
	case 2:
		DList.FromListToFile();
	}
}


// ======================= МЕНЮ ДОСТУПНЫХ ДЕЙСТВИЙ ДЛЯ ВСЕХ СТРУКТУР =======================

// меню для двусвязного списка
void menuForDoublyLinkedList(DoublyLinkedList& list) {
	using namespace std;
	int choice, numOfStack, num, n;

	cout << "\n\n======= МЕНЮ =======\nДоступные действия для двусвязного списка:\n 1 - вставка перед элементом\n 2 - вставка после элемента\n 3 - вставка элемента в конец списка\n 4 - найти элемент\n 5 - удалить элемент\n 6 - получить количество элментов в списке\n 7 - решить задачу\n";
	choice = getNumber();
	while (choice < 1 || choice>7) {
		cout << "\nОшибка!! Белым по черному написано, что надо цифру от 1 до 7 ввести! А ты че делаешь?? бе\n";
		choice = getNumber();
	}

	switch (choice) {
	case 1:
		num = getNumber();
		cout << "==== Ввод номера элемента, перед которым хотите вставить новый элемент ====\n";
		n = getNumber();

		list.insertBefore(n, num);
		break;
	case 2:
		num = getNumber();
		cout << "==== Ввод номера элемента, после которого хотите вставить новый элемент ====\n";
		n = getNumber();

		list.insertAfter(n, num);
		break;
	case 3:
		num = getNumber();

		list.pushBack(num);
		break;
	case 4:
		num = getNumber();

		list.contains(num);
		break;
	case 5:
		num = getNumber();

		list.pop(num);
		break;
	case 6:
		cout << "Количество элементов списка = " << list.getCount();
		break;
	case 7:
		return;
		break;
	}
}


// меню для двусвязного циклического списка
void menuForDoublyLinkedCyclicList(DoublyLinkedCyclicList& list) {
	using namespace std;
	int choice, numOfStack, num, n;

	cout << "\n\n======= МЕНЮ =======\nДоступные действия для двусвязного циклического списка:\n 1 - вставка перед элементом\n 2 - вставка после элемента\n 3 - вставка элемента в конец списка\n 4 - найти элемент\n 5 - удалить элемент\n 6 - получить количество элментов в списке\n 7 - решить задачу\n";
	choice = getNumber();
	while (choice < 1 || choice>7) {
		cout << "\nОшибка!! Белым по черному написано, что надо цифру от 1 до 7 ввести! А ты че делаешь?? бе\n";
		choice = getNumber();
	}

	switch (choice) {
	case 1:
		num = getNumber();
		cout << "==== Ввод номера элемента, перед которым хотите вставить новый элемент ====\n";
		n = getNumber();

		list.insertBefore(n, num);
		break;
	case 2:
		num = getNumber();
		cout << "==== Ввод номера элемента, после которого хотите вставить новый элемент ====\n";
		n = getNumber();

		list.insertAfter(n, num);
		break;
	case 3:
		num = getNumber();

		list.pushBack(num);
		break;
	case 4:
		num = getNumber();

		list.contains(num);
		break;
	case 5:
		num = getNumber();

		list.pop(num);
		break;
	case 6:
		cout << "Количество элементов списка = " << list.getCount();
		break;
	case 7:
		return;
		break;
	}
}

// меню для односвязного циклического списка
void menuForCyclicList(CyclicList& list) {
	using namespace std;
	int choice, numOfStack, num, n;

	cout << "\n\n======= МЕНЮ =======\nДоступные действия для односвязного циклического списка:\n 1 - вставка перед элементом\n 2 - вставка после элемента\n 3 - вставка элемента в конец списка\n 4 - найти элемент\n 5 - удалить элемент\n 6 - получить количество элментов в списке\n 7 - решить задачу\n";
	choice = getNumber();
	while (choice < 1 || choice>7) {
		cout << "\nОшибка!! Белым по черному написано, что надо цифру от 1 до 7 ввести! А ты че делаешь?? бе\n";
		choice = getNumber();
	}

	switch (choice) {
	case 1:
		num = getNumber();
		cout << "==== Ввод номера элемента, перед которым хотите вставить новый элемент ====\n";
		n = getNumber();

		list.insertBefore(n, num);
		break;
	case 2:
		num = getNumber();
		cout << "==== Ввод номера элемента, после которого хотите вставить новый элемент ====\n";
		n = getNumber();

		list.insertAfter(n, num);
		break;
	case 3:
		num = getNumber();

		list.pushBack(num);
		break;
	case 4:
		num = getNumber();

		list.contains(num);
		break;
	case 5:
		num = getNumber();

		list.pop(num);
		break;
	case 6:
		cout << "Количество элементов списка = " << list.getCount();
		break;
	case 7:
		return;
		break;
	}
}
