#pragma once
#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <vector>

class Node {
private:
	int data;
	Node* prev;
	Node* next;
public:
	Node() : data(0), prev(nullptr), next(nullptr) {};
	Node(int data) : data(data), prev(nullptr), next(nullptr) {};
	Node(const Node& other) : data(other.data), prev(nullptr), next(nullptr) {};
	~Node() {}

	int getData() const { return data; }
	Node* getNext() const { return next; }
	Node* getPrev() const { return prev; }

	void setData(int value) { data = value; }
	void setPrev(Node* prevNode) { prev = prevNode; }
	void setNext(Node* nextNode) { next = nextNode; }

	friend class DoublyLinkedList;
	friend class DoublyLinkedCyclicList;
	friend class CyclicList;
};


// ====== Класс: Двусвязный список ======
class DoublyLinkedList {
private:
	Node* head;  
	Node* tail;  
	int count;   

	// флаг, указывающий, что список преобразован в циклический с барьером
	bool isCyclicWithBarrier;  
public:
	// Конструкторы и деструктор
	DoublyLinkedList();
	DoublyLinkedList(const DoublyLinkedList& other);
	~DoublyLinkedList();

	void clear();		// Очистка списка
	void clearCyclic(); // Очистка списка, преобразованного в циклический

	// Операции добавления
	void pushFront(int num);     // Добавление в начало
	void pushBack(int num);      // Добавление в конец
	void insertAfter(int n, int num); // Вставка после элемента
	void insertBefore(int targetValue, int newValue); // Вставка перед элементом

	// Операции удаления
	void popFront();               // Удаление из начала
	void popBack();                // Удаление из конца
	void pop(int num);			   // Удаление элемента по значению 

	// Операции поиска
	Node* find(int value) const;   // Поиск узла по значению
	bool contains(int value) const; // Проверка наличия элемента

	// Операции доступа
	int getFirst() const;          // Получить первый элемент
	int getLast() const;           // Получить последний элемент
	int getCount() const { return count; } // Получить количество элементов в списке
	bool isEmpty() const { return head == nullptr; } // проверка пустоты списка

	// преобразование в циклический список с барьерным элементом
	void makeCyclicList();

	// перемещение элементов с нечетными номерами в конец списка
	void switchElements();

	void print() const;		// вывод
	void FromListToFile();  // вывод в файл
};


// ====== Класс: Двусвязный циклический список ======
class DoublyLinkedCyclicList {
private:
	Node* head;
	int count;
public:
	// Конструкторы и деструктор
	DoublyLinkedCyclicList();
	DoublyLinkedCyclicList(const DoublyLinkedCyclicList& other);
	~DoublyLinkedCyclicList();

	// Очистка списка
	void clear();

	void pushBack(int num);			  // Вставка в конец списка
	void insertAfter(int n, int num); // Вставка после элемента
	void insertBefore(int targetValue, int newValue); // Вставка перед элементом

	void pop(int num);    // Удаление элемента                 
	
	// Операции поиска
	Node* find(int value) const;   // Поиск узла по значению
	bool contains(int value) const; // Проверка наличия элемента

	// Получить элемент
	int getData(Node* q) const;   

	// Получить количество элементов в списке
	int getCount() const { return count; }

	// проверка пустоты списка
	bool isEmpty() const { return head == nullptr; }

	// Проверка соседей элемента на одинаковость
	Node* checkNeighbors();

	void FromListToFile();	// вывод в файл
	void print() const;		// вывод

	// нахождение максимальной невозрастающей последовательности
	void MaxSequence();
};


// ====== Класс: Односвязный циклический список ======
class CyclicList {
private:
	Node* head;
	int count;
public:
	// Конструкторы и деструктор
	CyclicList();
	CyclicList(const CyclicList& other);
	~CyclicList();

	// Очистка списка
	void clear();

	void pushBack(int num); // Вставка элемента в конец списка
	void insertAfter(int n, int num);   // Вставка после элемента с номером n
	void insertBefore(int n, int num);  // Вставка перед элементом с номером n

	void pop(int num);   // Удаление элемента по значению

	Node* find(int value) const;      // Поиск узла по значению
	bool contains(int value) const;   // Проверка наличия элемента
	
	// проверка пустоты списка
	bool isEmpty() const { return head == nullptr; }

	// Получить количество элементов в списке
	int getCount() const { return count; }  

	// Получить данные узла
	int getData(Node* q) const;  

	// Вывод
	void print() const;

	// вывод в файл
	void FromListToFile();

	// вывод в файл с шагом 4
	void OutputToFile();
};


// проверка ввода
std::string getText();
int getNumber();


// ==== Меню для ввода всех структур ====
void inputForDoublyLinkedList(DoublyLinkedList& DList); 
void inputForDoublyLinkedCyclicList(DoublyLinkedCyclicList& DList);
void inputForCyclicList(CyclicList& DList);


// ==== Меню для вывода всех структур ====
void OutputForDoublyLinkedCyclicList(DoublyLinkedCyclicList& DList);
void OutputForDoublyLinkedList(DoublyLinkedList& DList);
void OutputForCyclicList(CyclicList& DList);


// ==== Меню c выбором доступных действий для всех структур ====
void menuForDoublyLinkedList(DoublyLinkedList& list);
void menuForDoublyLinkedCyclicList(DoublyLinkedCyclicList& list);
void menuForCyclicList(CyclicList& list);


// Задачи
void task_1();
void task_2();
void task_3();
void task_4();
void task_5();


#endif
