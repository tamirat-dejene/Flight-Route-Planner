#include<iostream>
using namespace std;

template <typename T>
class Node{
private:
	T data;
	Node* next;
public:
	Node() : next(nullptr) {}
	Node(T value) : data(value), next(nullptr) {}

	T getData() {
		return this->data;
	}
	void setData(T data) {
		this->data = data;
	}
	Node<T>* getNext() {
		return this->next;
	}
	void setNext(Node* next) {
		this->next = next;
	}
};

template <typename T>
class Queue {
private:
	Node<T>* front;
	Node<T>* rear;
	int size;
public:
	Queue() : front(nullptr), rear(nullptr), size(0) {}

	int getSize() {
		return size;
	}

	T getFront() {
		if (front != nullptr)
			return front->getData();
		return T();
	}

	bool isEmpty() {
		return size == 0;
	}

	bool contains(T value) {
		if (size == 0)
			return false;
		Node<T>* temp = front;
		while (temp->getNext() != nullptr) {
			if (temp->getData() == value)
				return true;
			temp = temp->getNext();
		}
		return false;
	}

	void enqueue(T data) {
		Node<T>* newNode = new Node<T>(data);
		if (front == nullptr) {
			front = rear = newNode;
			++size;
			return;
		}
		rear->setNext(newNode);
		++size;
		rear = newNode;
	}

	T dequeue() {
		if (front == nullptr) {
			return T();
		}
		Node<T>* del = front;
		front = front->getNext();
		//delete del;
		--size;
		return del->getData();
	}
};