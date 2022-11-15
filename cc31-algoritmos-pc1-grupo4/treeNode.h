#pragma once

#include"Lib.h"

template<class T>
struct treeNode {
    T data1, data2, data3;
    treeNode* left;
    treeNode* right;
    treeNode(T _data1, T _data2, T _data3) {
        data1 = _data1;
        data2 = _data2;
        data3 = _data3;
        left = right = nullptr;
    }
};