#pragma once

#include"Node.h"

template<class T>
class List {
private:
	Node<T>* start;
	uint size;
	string filename;
public:
	List(string _filename) {
		start = nullptr;
		size = 0;
		filename = _filename;
	}
	~List() {}

	void push(T data1, T data2, T data3) {
		Node<T>* newNode = new Node<T>(data1, data2, data3);

		if (start == nullptr)
			start = newNode;
		else {
			newNode->next = start;
			start = newNode;
		}

		size++;
	}

	void showAll() {
		Node<T>* current = start;

		while (current != nullptr) {
			cout << "[" << current->data1 << "," << current->data2 << "," << current->data3 << "]\n";
			current = current->next;
		}
		cout << "\nTotal de datos -> " << size << "\n\n";
	}

	auto getNode(T key) {
		Node<T> node;
		Node<T>* current = start;

		while (current != nullptr) {
			if (current->data1 == key) {
				node.data1 = current->data1; node.data2 = current->data2; node.data3 = current->data3;
			}
			current = current->next;
		}

		return node;
	}

	bool search(T key) {
		Node<T>* current = start;

		while (current != nullptr) {
			if (current->data1 == key) {
				return true;
			}
			current = current->next;
		}

		return false;
	}

	uint getSize() { return size; }
	string getCSV() { return filename; }
};