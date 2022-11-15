#pragma once
#include"Lib.h"

template<class T>
class List;

template<class T>
struct Node {
	T data1,data2,data3;
	Node<T>* next;
	friend class List<T>;
	Node(T data1, T data2, T data3) {
		this->data1 = data1;
		this->data2 = data2;
		this->data3 = data3;

		next = nullptr;
	}
	Node() {}
	Node(Node*toCopy) {
		this->data1 = toCopy->data1;
		this->data2 = toCopy->data2;
		this->data3 = toCopy->data3;

		next = toCopy->next;
	}
};


