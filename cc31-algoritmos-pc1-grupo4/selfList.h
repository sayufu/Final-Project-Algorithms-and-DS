#pragma once
#include"Lib.h"
#include"Node.h"

template<class T>
class selfList {
private:
	Node<T>* head;
	int size;
	string filename;
public:
	selfList(string _filename) {
		head = nullptr;
		size = 0;
		filename = _filename;
	}

	void push(T key1, T key2, T key3) {
		Node<T>* newNode = new Node<T>(key1, key2, key3);

		if (head == nullptr)
			head = newNode;
		else {
			newNode->next = head;
			head = newNode;
		}
		size++;
	}

	void search(T key) {
		Node<T>* current = head;
		Node<T>* temp = nullptr;
		bool found = false;

		if (current->data1 == key) {
			cout << "Found " << head->data1 << "\n";
			return;
		}
		while (current->next != nullptr) {
			if ((current->next)->data1 == key) {
				cout << "Found " << key << "and pushed to front\n";
				cout << "[" << (current->next)->data1 << " , " << (current->next)->data2 << " , " << (current->next)->data3 << "]";

				found = true;

				temp = (current->next)->next;
				(current->next)->next = head;
				head = current->next;
				current->next = temp;
				break;
			}
			current = current->next;
		}
		if (!found) {
			cout << "Not found " << key << "\n";
		}
	}

	void showAll() {
		Node<T>* current = head;

		while (current != nullptr) {
			cout << "[" << current->data1 << " , " << current->data2 << " , " << current->data3 << "]\n";
			current = current->next;
		}
		cout << "\n";
	}

	string getCSV() { return filename; }
};
