# include "Header.h"

void task_1(){
	CyclicList list;
	
	inputForCyclicList(list);

	menuForCyclicList(list);

	list.OutputToFile();

	OutputForCyclicList(list);
}

void task_2() {
	DoublyLinkedCyclicList list;

	inputForDoublyLinkedCyclicList(list);

	menuForDoublyLinkedCyclicList(list);

	list.checkNeighbors();
	OutputForDoublyLinkedCyclicList(list);
}

void task_3() {
	DoublyLinkedList list;

	inputForDoublyLinkedList(list);

	menuForDoublyLinkedList(list);

	list.switchElements();

	menuForDoublyLinkedList(list);

	OutputForDoublyLinkedList(list);
}

void task_4() {
	using namespace std;

	int cnt, input;
	DoublyLinkedList list;

	inputForDoublyLinkedList(list);

	menuForDoublyLinkedList(list);
	
	list.makeCyclicList();

	cout << "\n\n=== Вывод списка ===" << endl;

	cout << "Доступные способы вывода списка:\n 1 - в консоль\n 2 - в файл" << endl;
	input = getNumber();

	while (input < 1 || input>2) {
		cout << "Ошибка! Нужна цифра 1 или 2!\n ";
		input = getNumber();
	}

	switch (input) {
	case 1:
		cout << endl;
		list.print();
		cout << endl;
		break;
	case 2:
		list.FromListToFile();
	}
}

void task_5() {
	using namespace std;
	DoublyLinkedCyclicList list;

	int cnt, input;
	vector<int> result;

	inputForDoublyLinkedCyclicList(list);

	menuForDoublyLinkedCyclicList(list);

	list.MaxSequence(result);

	cout << "\n\n=== Вывод ===" << endl;

	cout << "Доступные способы вывода последовательности:\n 1 - в консоль\n 2 - в файл" << endl;
	input = getNumber();

	while (input < 1 || input>2) {
		cout << "Ошибка! Нужна цифра 1 или 2!\n ";
		input = getNumber();
	}

	switch (input) {
	case 1:
		cout << endl;
		cout << "Максимальная невозрастающая последовательность: ";
		for (int i : result) {
			cout << i << " ";
		}
		cout << endl;
		break;
	case 2:
		string filename;
		filename = getText();
		ofstream file(filename);

		if (!file.is_open()) {
			cout << "\nОшибка открытия файла!\n";
		}

		file << "Максимальная невозрастающая последовательность: ";
		for (int i : result) {
			file << i << " ";
		}

		file.close();

		break;
	}
}
