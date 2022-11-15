#pragma once
#include"Lib.h"

template<class T>
bool circleSortHelper(vector<T>* arr, int start, int end) {

	if (start == end) return false;

	bool res = false;

	int low = start, high = end;

	while (low < high) {
		if (int(arr->at(low).data1[0]) > int(arr->at(high).data1[0])) {
			swap(arr->at(low), arr->at(high));
			res = true;
		}
		low++;
		high--;
	}
	if (low == high) {
		if (int(arr->at(low).data1[0]) > int(arr->at(high+1).data1[0])) {
			res = true;
			swap(arr->at(low), arr->at(high + 1));
		}
	}

	int mid = start + (end - start) / 2;
	bool first = circleSortHelper(arr, start, mid);
	bool second = circleSortHelper(arr, mid + 1, end);
	return res || first || second;
}

template<class T>
void circleSort(vector<T>* arr, int start, int end) {
	while (circleSortHelper(arr, start, end));
}