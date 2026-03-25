# include "Header.h"

// ======================== КЛАСС: ОДНОСВЯЗНЫЙ ЦИКЛИЧЕСКИЙ СПИСОК ========================


// Конструктор по умолчанию
CyclicList::CyclicList() : head(nullptr), count(0) {}

// Конструктор копирования
CyclicList::CyclicList(const CyclicList& other)
    : head(nullptr), count(0) {

    if (!other.isEmpty()) {
        Node* current = other.head;

        Node* newNode = new Node(current->getData());
        head = newNode;
        Node* prev = newNode;

        current = current->getNext();

        while (current != other.head) {
            newNode = new Node(current->getData());

            prev->setNext(newNode);

            prev = newNode;
            current = current->getNext();
        }

        // Замыкаем цикл
        prev->setNext(head);

        count = other.count;
    }
}

// Деструктор
CyclicList::~CyclicList() {
    clear();
}

// Очистка списка
void CyclicList::clear() {
    if (isEmpty()) return;

    // Разрываем цикл
    Node* last = head;
    while (last->getNext() != head) {
        last = last->getNext();
    }
    last->setNext(nullptr);

    // Удаляем все узлы
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->getNext();
        delete current;
        current = next;
    }

    head = nullptr;
    count = 0;
}

// Вставка элемента в конец списка
void CyclicList::pushBack(int num) {
    Node* newNode = new Node(num);

    if (isEmpty()) {
        newNode->setNext(newNode);  // Ссылается сам на себя
        head = newNode;
        count = 1;
        return;
    }

    Node* last = head;
    while (last->getNext() != head) {
        last = last->getNext();
    }

    newNode->setNext(head);
    last->setNext(newNode);

    count++;
}

// Вставка после элемента с номером n
void CyclicList::insertAfter(int n, int num) {

    if (isEmpty()) {
        Node* newNode = new Node(num);
        newNode->setNext(newNode);
        head = newNode;
        count = 1;
        return;
    }

    Node* q = head;
    for (int i = 1; i < n; i++) {
        q = q->getNext();
    }

    Node* newNode = new Node(num);

    newNode->setNext(q->getNext());
    q->setNext(newNode);

    count++;
}

// Вставка перед элементом с номером n
void CyclicList::insertBefore(int n, int num) {

    if (isEmpty()) {
        Node* newNode = new Node(num);
        newNode->setNext(newNode);
        head = newNode;
        count = 1;
        return;
    }

    if (n == 1) {
        Node* newNode = new Node(num);
        Node* last = head;
        while (last->getNext() != head) {
            last = last->getNext();
        }

        newNode->setNext(head);
        last->setNext(newNode);
        head = newNode;
        count++;
        return;
    }

    Node* q = head;
    for (int i = 1; i < n - 1; i++) {
        q = q->getNext();
    }

    Node* newNode = new Node(num);

    newNode->setNext(q->getNext());
    q->setNext(newNode);

    count++;
}

// Удаление элемента по значению
void CyclicList::pop(int num) {
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

    int data = temp->getData();

    if (count == 1) {
        delete temp;
        head = nullptr;
    }
    else {
        Node* prev = head;
        while (prev->getNext() != temp) {
            prev = prev->getNext();
        }

        prev->setNext(temp->getNext());

        if (temp == head) {
            head = temp->getNext();
        }

        delete temp;
    }

    count--;
}

// Поиск узла по значению
Node* CyclicList::find(int value) const {
    using namespace std;

    if (isEmpty()) return nullptr;

    Node* current = head;
    do {
        if (current->getData() == value) {
            cout << "Узел с элементом " << value << " найден" << endl;
            return current;
        }
        current = current->getNext();
    } while (current != head);

    cout << "Узел с элементом " << value << " не найден" << endl;
    return nullptr;
}

// Проверка наличия элемента
bool CyclicList::contains(int value) const {
    return find(value) != nullptr;
}

// Получить данные узла
int CyclicList::getData(Node* q) const {
    if (q == nullptr) return -1;
    return q->getData();
}

// Вывод списка
void CyclicList::print() const {
    using namespace std;

    if (isEmpty()) {
        cout << "Список пуст" << endl;
        return;
    }

    cout << "Односвязный циклический список: ";

    Node* current = head;
    do {
        cout << current->getData() << " ";
        current = current->getNext();
    } while (current != head);

    cout << endl;
}

// вывод в файл
void CyclicList::FromListToFile() {
    using namespace std;

    int data, num = 0;
    string filename;
    Node* q = head;

    filename = getText();

    ofstream file(filename);

    if (!file.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
    }

    if (file.is_open()) {
        file << "Список: ";
        while (num != count) {
            data = q->data;
            file << data << " ";
            q = q->next;
            num++;
        }
    }
    file.close();

    cout << "Список загружен в файл " << filename << " 0-0\n";

}

// вывод в файл с шагом 4
void CyclicList::OutputToFile() {
    using namespace std;

    string filename = getText();
    ofstream file(filename);

    if (!file.is_open()) {
        cout << "Ошибка открытия файла!";
        return;
    }

    if (head == nullptr) {
        file << "Список пуст!";
        file.close();
        return;
    }

    int step = 1;
    int n = count;

    Node* current = head;
    Node* prev = nullptr;

    Node* last = head;
    while (last->next != head) {
        last = last->next;
    }
    prev = last;

    while (n > 0) {
        file << current->data << " ";

        Node* toDelete = current;
        prev->next = current->next;
        current = current->next;

        if (toDelete == head) {
            head = current;
        }

        delete toDelete;
        n--;
        step++;

        if (n > 0) {
            for (int i = 0; i < 3; i++) {  
                prev = current;
                current = current->next;
            }
        }
    }

    head = nullptr;
    count = 0;
    file.close();

    cout << "Результат записан в файл\n";
}
