# include "Header.h"

// ==================== КЛАСС: ДВУСВЯЗНЫЙ СПИСОК ====================


// Конструктор по умолчанию
DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr), count(0), isCyclicWithBarrier(false) {}

// Конструктор копирования 
DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& other)
	: head(nullptr), tail(nullptr), count(0) {
	Node* current = other.head;
	while (current != nullptr) {
		pushBack(current->data);
		current = current->next;
	}
}

// Очистка списка
void DoublyLinkedList::clear() {
	using namespace std;

	Node* current = head;
	while (current != nullptr) {
		Node* next = current->next;
		delete current;
		current = next;
	}
	head = nullptr;
	tail = nullptr;
	count = 0;
	cout << "Список очищен" << endl;
}

// Очистка списка, преобразованного в циклический
void DoublyLinkedList::clearCyclic() {
	if (head == nullptr) return;

	Node* barrier = head;
	Node* first = barrier->next;
	Node* last = barrier->prev;

	if (first != barrier) {
		last->next = nullptr;
		first->prev = nullptr;
		barrier->next = nullptr;
		barrier->prev = nullptr;

		Node* current = first;
		while (current != nullptr) {
			Node* next = current->next;
			delete current;
			current = next;
		}
	}

	delete barrier;

	head = nullptr;
	tail = nullptr;
	count = 0;
	isCyclicWithBarrier = false;
}

// Деструктор
DoublyLinkedList::~DoublyLinkedList() {
	if (isCyclicWithBarrier) {
		clearCyclic();
	}
	else {
		clear();
	}
}


// Добавление в начало
void DoublyLinkedList::pushFront(int num) {

	Node* newNode = new Node(num);

	newNode->next = head;
	newNode->prev = nullptr;

	if (head) head->prev = newNode;
	head = newNode;
	if (!tail) tail = head;

	count++;
}

// Добавление в конец
void DoublyLinkedList::pushBack(int num) {

	Node* newNode = new Node(num);

	newNode->next = nullptr;
	newNode->prev = tail;

	if (tail) tail->next = newNode;
	tail = newNode;
	if (!head) head = tail;

	count++;
}

// Вставка после элемента
void DoublyLinkedList::insertAfter(int n, int num) {
	//cout << "Введите номер элемента, после которого вы хотите вставить свое число: ";
	using namespace std;

	if (isEmpty()) {
		cout << "Список пуст" << endl;
		return;
	}

	Node* q = head;
	for (int i = 1; i < n; i++) {
		q = q->next;
	}

	Node* newNode = new Node(num);

	if (q->next == nullptr) {
		pushBack(num);
	}
	else {
		newNode->next = q->next;
		q->next->prev = newNode;
		newNode->prev = q;
		q->next = newNode;
	}
	count++;
}

// Вставка перед элементом
void DoublyLinkedList::insertBefore(int n, int num) {
	using namespace std;

	if (isEmpty()) {
		cout << "Список пуст" << endl;
		return;
	}

	Node* q = head;
	for (int i = 1; i < n; i++) {
		q = q->next;
	}

	Node* newNode = new Node;
	newNode->data = num;

	if (q->prev == nullptr) {
		pushFront(num);
	}
	else {
		q->prev->next = newNode;
		newNode->prev = q->prev;
		newNode->next = q;
		q->prev = newNode;

	}
	count++;
}


// Удаление из начала
void DoublyLinkedList::popFront() {
	using namespace std;

	if (isEmpty()) {
		cout << "Список пуст, удаление невозможно" << endl;
		return;
	}

	Node* temp = head;
	int value = head->data;

	if (head == tail) {
		// В списке один элемент
		head = tail = nullptr;
	}
	else {
		head = head->next;
		head->prev = nullptr;
	}

	delete temp;
	count--;
	cout << "Удалено из начала: " << value << endl;

}

// Удаление из конца
void DoublyLinkedList::popBack() {
	using namespace std;

	if (isEmpty()) {
		cout << "Список пуст, удаление невозможно" << endl;
		return;
	}

	Node* temp = tail;
	int value = tail->data;

	if (tail == head) {
		// В списке один элемент
		tail = head = nullptr;
	}
	else {
		tail = tail->prev;
		tail->next = nullptr;
	}

	delete temp;
	count--;
	cout << "Удалено из конца: " << value << endl;
}

// Удаление элемента по значению 
void DoublyLinkedList::pop(int num) {
	using namespace std;

	if (isEmpty()) {
		cout << "Список пуст, удаление невозможно" << endl;
		return;
	}

	Node* temp = find(num);
	if (temp == nullptr) {
		cout << "Элемент " << num << " не найден" << endl;
		return;
	}

	int data = temp->data;

	if (count == 1) {
		delete temp;
		head = nullptr;
	}
	else {
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;

		if (temp == head) {
			head = temp->next;
		}

		delete temp;
	}

	count--;
}


// Поиск узла по значению
Node* DoublyLinkedList::find(int value) const {
	using namespace std;

	Node* q = head;

	while (q) {
		if (q->data != value) {
			q = q->next;
		}
		else {
			cout << "Узел с данным элементом найден" << endl;
			return q;
		}
	}

	if (q->data != value) {
		cout << "Узел с данным элементом не найден" << endl;
		return nullptr;
	}

}

// Проверка наличия элемента
bool DoublyLinkedList::contains(int value) const {
	using namespace std;

	Node* q = head;

	while (q && q->data != value) {
		q = q->next;
	}

	if (q->data == value) {
		cout << "Элемент найден!" << endl;
		return true;
	}
	else {
		cout << "Элемент не найден!" << endl;
		return false;
	}

}

// Получить первый элемент
int DoublyLinkedList::getFirst() const {
	return head->data;
}

// Получить последний элемент
int DoublyLinkedList::getLast() const {
	return tail->data;
}

// преобразование в циклический список с барьерным элементом
void DoublyLinkedList::makeCyclicList() {
	Node* barrierElement = new Node;
	barrierElement->data = 0;

	if (isEmpty()) {
		barrierElement->next = barrierElement;
		barrierElement->prev = barrierElement;
		head = barrierElement;
		tail = barrierElement;
	}
	else {
		barrierElement->next = head;
		barrierElement->prev = tail;
		head->prev = barrierElement;
		tail->next = barrierElement;
		head = barrierElement;  // барьерный элемент становится головой
		tail = barrierElement;  // и хвостом тоже 
	}

	count++;
	isCyclicWithBarrier = true;  // устанавливаем флаг
}

// перемещение элементов с нечетными номерами в конец списка
void DoublyLinkedList::switchElements() {
	using namespace std;
	Node* current = head;
	Node* Next;
	head = head->next;
	current->prev = tail;
	head->prev = nullptr;
	current->next = nullptr;
	tail->next = current;
	tail = current;
	current = head;
	int n = 2;

	while (n <= count) {
		if (n % 2 != 0) {
			Next = current->next;
			current->next->prev = current->prev;
			current->prev->next = current->next;
			tail->next = current;
			current->prev = tail;
			current->next = nullptr;
			tail = current;
			current = Next;
		}
		else {
			current = current->next;
		}
		n++;
	}
}

// вывод
void DoublyLinkedList::print() const {
	using namespace std;

	if (isEmpty()) {
		cout << "Список пуст" << endl;
		return;
	}

	cout << "Cписок: ";

	if (isCyclicWithBarrier) {
		// Циклический список с барьером
		Node* current = head->next;
		while (current != head) {
			cout << current->getData() << " ";
			current = current->next;
		}
	}
	else {
		// Обычный линейный список
		Node* current = head;
		while (current != nullptr) {
			cout << current->getData() << " ";
			current = current->next;
		}
	}
	cout << endl;
}

// вывод в файл
void DoublyLinkedList::FromListToFile() {
	using namespace std;

	int data;
	string filename;
	Node* q = head;

	filename = getText();

	ofstream file(filename);

	if (!file.is_open()) {
		cout << "Ошибка открытия файла!" << endl;
	}

	file << "Список: ";

	if (isCyclicWithBarrier) {
		// Циклический список с барьером
		Node* current = head->next;
		while (current != head) {
			file << current->getData() << " ";
			current = current->next;
		}
	}
	else {
		// Обычный линейный список
		Node* current = head;
		while (current != nullptr) {
			file << current->getData() << " ";
			current = current->next;
		}
	}


	file.close();

	cout << "Список загружен в файл " << filename << " 0-0\n";

}
