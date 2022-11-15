#pragma once

#include"Lib.h"

template<class T>
void gnomeSort(vector<T>* arr) {
    int i = 0;

    while (i < arr->size()) {
        cout << i << "\n";
        if (i == 0) {
            i++;
        }
        if (int(arr->at(i).data1[0]) >= int(arr->at(i-1).data1[0])) {
            i++;
        }
        else {
            swap(arr->at(i), arr->at(i - 1));
            i--;
        }
    }
}


