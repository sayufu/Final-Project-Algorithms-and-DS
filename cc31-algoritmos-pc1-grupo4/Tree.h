#pragma once

#include"Lib.h"
#include"treeNode.h"

template<class T>
class Tree {
private:
    string filename;
    treeNode<T>* root;
    void _postorder(treeNode<T>* node) {
        if (node == nullptr) {
            return;
        }

        _postorder(node->left);
        _postorder(node->right);
        cout << "[" << node->data1 << " , " << node->data2 << " , " << node->data3 << "]\n";
    }
    treeNode<T>* _insert(treeNode<T>* node, T data1, T data2, T data3) {
        if (node == nullptr) {
            return new treeNode<T>(data1, data2, data3);
        }

        if (data1 < node->data1) {
            node->left = _insert(node->left, data1, data2, data3);
        }
        else {
            node->right = _insert(node->right, data1, data2, data3);
        }

        return node;
    }

public:
    Tree(string _filename) { 
        root = nullptr; 
        filename = _filename;
    }
    ~Tree() {}
    void showAll() { 
        _postorder(root); cout << "\n"; 
    }
    void push(T data1, T data2, T data3) { 
        this->root = _insert(root, data1, data2, data3); 
    }

    treeNode<T>* getRoot() { return root; }
    string getCSV() { return filename; }
};