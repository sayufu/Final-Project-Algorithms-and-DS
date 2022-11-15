#pragma once
#include"Lib.h"

template<typename T>
class heaps;

template<typename T>
class datos {
private:
	T data1, data2, data3;
	friend class heaps<T>;
public:
	datos(T data1, T data2, T data3) {
		this->data1 = data1;
		this->data2 = data2;
		this->data3 = data3;
	}
	datos(datos* toCopy) {
		this->data1 = toCopy->data1;
		this->data2 = toCopy->data2;
		this->data3 = toCopy->data3;
	}
	~datos() {}
};

