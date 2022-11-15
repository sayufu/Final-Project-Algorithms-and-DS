#pragma once

#include"Lib.h"

template<class T>
struct forVector {
	T data1, data2, data3, data4;

	forVector(T _data1, T _data2, T _data3, T _data4) {
		this->data1 = _data1;
		this->data2 = _data2;
		this->data3 = _data3;
		this->data4 = _data4;
	}
	forVector() {}
};
