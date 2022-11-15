#pragma once

#include"Lib.h"
#include"Playlist.h"

template<class T>
class hashList {
private:
    T* head;
    int size;
public:
    hashList() {
        head = nullptr;
        size = 0;
    }
    ~hashList() {}

	void push(int id, string name, string author, string album) {
		T* newNode = new T(id, name, author, album);

		if (head == nullptr)
			head = newNode;
		else {
			newNode->next = head;
			head = newNode;
		}

		size++;
	}

	void showAll() {
		T* current = head;

		while (current != nullptr) {
			cout << "[" << current->id << " , " << current->name << " , " << current->author << " , " << current->album << "]\n";
			current = current->next;
		}
		cout << "\nTotal de datos -> " << size << "\n\n";
	}

	auto getNode(string key) {
		T node;
		T* current = head;

		while (current != nullptr) {
			if (current->data1 == key) {
				node.data1 = current->data1; node.data2 = current->data2; node.data3 = current->data3;
			}
			current = current->next;
		}

		return node;
	}

	bool search(T key) {
		T* current = head;

		while (current != nullptr) {
			if (current->data1 == key) {
				return true;
			}
			current = current->next;
		}

		return false;
	}

	void remove(int toDelete) {
		if (head == nullptr) {
			cout << "No lo encontramos!\n";
			return;
		}

		int count = 0;
		T* current = head;

		if (current->id == toDelete) {
			T* newHead = current->next;
			head = newHead;
			free(current);
			cout << toDelete << " eliminado, era el header del contenedor\n";
			return;
		}
		    
		while (current->next != nullptr) {
			if ((current->next)->id == toDelete) {
				T* newNext = (current->next)->next;
				free(current->next); /*Node to delete*/
				current->next = newNext;
				cout << toDelete << " eliminado, esto tomo recorrer " << count << " nodos\n";
				return;
			}
			count++;
			current = current->next;
		}

		cout << "No encontramos " << toDelete << " en el hash map\n";
	}

	uint getSize() { return size; }
};