#pragma once
#include"Lib.h"

template<class T>
T getMax(vector<T>* arr) {
    T max = arr->at(0);

    for (int i = 1; i < arr->size(); i++) {
        if (max.data1[0] < arr->at(i).data1[0]) {
            max = arr->at(i);
        }
    }

    return max;
}

template<class T>
T getMin(vector<T>* arr) {
    T min = arr->at(0);

    for (int i = 1; i < arr->size(); i++) {
        if (min.data1[0] > arr->at(i).data1[0]) {
            min = arr->at(i);
        }
    }

    return min;
}

template<class T>
void countSort(vector<T>* arr) {
    int max = int(getMax(arr).data1[0]);
    int min = int(getMin(arr).data1[0]);
    
    int range = max - min + 1;

    vector<int>count(range);

    vector<T>output(arr->size());

    for (int i = 0; i < arr->size(); i++) {
        count[int(arr->at(i).data1[0]) - min]++;
    }

    for (int i = 1; i < count.size(); i++) {
        count[i] += count[i - 1];
    }

    for (int i = arr->size() - 1; i >= 0; i--) {
        output[count[int(arr->at(i).data1[0]) - min] - 1] = arr->at(i);
        count[int(arr->at(i).data1[0]) - min]--;
    }

    for (int i = 0; i < arr->size(); i++) {
        arr->at(i) = output[i];
    }
}