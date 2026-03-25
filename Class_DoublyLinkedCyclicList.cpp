# include "Header.h"

// ==================== КЛАСС: ДВУСВЯЗНЫЙ ЦИКЛИЧЕСКИЙ СПИСОК ====================


// Конструктор по умолчанию - пустой список
DoublyLinkedCyclicList::DoublyLinkedCyclicList() : head(nullptr), count(0) {}

// Конструктор копирования 
DoublyLinkedCyclicList::DoublyLinkedCyclicList(const DoublyLinkedCyclicList& other)
    : head(nullptr), count(0) {

    if (!other.isEmpty()) {
        Node* current = other.head;

        Node* newNode = new Node(current->getData());
        head = newNode;
        Node* prev = newNode;

        current = current->next;

        while (current != other.head) {
            newNode = new Node(current->getData());

            prev->setNext(newNode);
            newNode->setPrev(prev);

            prev = newNode;
            current = current->next;
        }

        // Замыкаем цикл 
        prev->setNext(head);
        head->setPrev(prev);

        count = other.count;
    }
}

// Деструктор
DoublyLinkedCyclicList::~DoublyLinkedCyclicList() {
    clear();
}

// Очистка 
void DoublyLinkedCyclicList::clear() {
    if (isEmpty()) return;

    // Разрываем цикл
    Node* last = head->prev;
    last->setNext(nullptr);

    // Удаляем все узлы
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }

    head = nullptr;
    count = 0;
}

// Вставка элемента в конец списка
void DoublyLinkedCyclicList::pushBack(int num) {

    Node* newNode = new Node(num);

    if (isEmpty()) {
        newNode->setNext(newNode);  
        newNode->setPrev(newNode);
        head = newNode;
        count = 1;
        return;
    }

    Node* last = head->prev;

    newNode->setNext(head);
    newNode->setPrev(last);

    last->setNext(newNode);
    head->setPrev(newNode);

    count++;
}

// Вставка после элемента 
void DoublyLinkedCyclicList::insertAfter(int n, int num) {

    if (isEmpty()) {
        Node* newNode = new Node(num);
        newNode->setNext(newNode);  
        newNode->setPrev(newNode);
        head = newNode;
        count = 1;
        return;
    }

    Node* q = head;
    for (int i = 1; i < n; i++) {
        q = q->next;
    }

    Node* newNode = new Node(num);

    newNode->setPrev(q);
    newNode->setNext(q->next);

    q->next->setPrev(newNode);
    q->setNext(newNode);

    count++;
}

// Вставка перед элементом 
void DoublyLinkedCyclicList::insertBefore(int n, int num) {

    if (isEmpty()) {
        Node* newNode = new Node(num);
        newNode->setNext(newNode);
        newNode->setPrev(newNode);
        head = newNode;
        count = 1;
        return;
    }

    Node* q = head;
    for (int i = 1; i < n; i++) {
        q = q->next;
    }

    Node* newNode = new Node(num);

    newNode->setPrev(q->prev);
    newNode->setNext(q);

    q->prev->setNext(newNode);
    q->setPrev(newNode);

    if (q == head) {
        head = newNode;
    }

    count++;
}

// Удаление элемента по значению 
void DoublyLinkedCyclicList::pop(int num) {
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
Node* DoublyLinkedCyclicList::find(int value) const {
	using namespace std;

    if (isEmpty()) return nullptr;

    Node* current = head;
    do {
        if (current->getData() == value) {
            cout << "Узел с элементом " << value << " найден" << endl;
            return current;
        }
        current = current->next;
    } while (current != head);

    cout << "Узел с элементом " << value << " не найден" << endl;
    return nullptr;
}

// Проверка наличия элемента 
bool DoublyLinkedCyclicList::contains(int value) const {
    return find(value) != nullptr;
}

// Получить элемент 
int DoublyLinkedCyclicList::getData(Node* q) const {
    if (q == nullptr) return -1;
    return q->getData();
}

// Проверка соседей элемента на одинаковость
Node* DoublyLinkedCyclicList::checkNeighbors() {
    using namespace std;

    if (isEmpty()) {
        cout << "Список пуст" << endl;
        return nullptr;
    }

    if (head->next == head) {
        delete head;
        head = nullptr;
        cout << "Удален последний элемент" << endl;
        return nullptr;
    }

    if (head->next->next == head) {
        clear();
        cout << "Все элементы удалены" << endl;
        return nullptr;
    }

    bool found = false;
    Node* current = head;

    do {
        if (current->prev->getData() == current->next->getData()) {
            found = true;
            break;
        }
        current = current->next;
    } while (current != head);

    if (!found) {
        cout << "Элементов с равными соседями не найдено" << endl;
        return head->prev;
    }

    Node* toDelete = current;
    Node* nextNode = current->next;

    toDelete->prev->next = toDelete->next;
    toDelete->next->prev = toDelete->prev;

    if (toDelete == head) {
        head = nextNode;
    }

    delete toDelete;

    if (!isEmpty()) {
        return checkNeighbors();
    }

    return nullptr;
}

// Вывод 
void DoublyLinkedCyclicList::print() const {
    using namespace std;

    if (isEmpty()) {
        cout << "Список пуст" << endl;
        return;
    }

    cout << "Cписок: ";

    Node* current = head;
    do {
        cout << current->getData() << " ";
        current = current->next;
    } while (current != head);

}

// вывод в файл
void DoublyLinkedCyclicList::FromListToFile() {
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

// максимальная невозрастающая последовательность
void DoublyLinkedCyclicList::MaxSequence() {
    using namespace std;

    if (isEmpty()) {
        cout << "Список пуст" << endl;
        return;
    }

    vector<int> arr;
    Node* current = head;
    do {
        arr.push_back(current->getData());
        current = current->next;
    } while (current != head);

    int n = arr.size();

    int maxLen = 1;
    int bestStart = 0;

    for (int start = 0; start < n; start++) {
        int len = 1;
        int idx = start;

        while (len < n && arr[(idx + 1) % n] <= arr[idx]) {
            len++;
            idx = (idx + 1) % n;
        }

        if (len > maxLen) {
            maxLen = len;
            bestStart = start;
        }

        if (maxLen == n) break;
    }

    clear();

    for (int i = 0; i < maxLen; i++) {
        int num = arr[(bestStart + i) % n];
        pushBack(num); 
    }

}






