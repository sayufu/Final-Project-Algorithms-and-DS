#pragma once
#include"structheap.h"
#include"Lib.h"


template <typename T>
class heaps {
private:
    vector<datos<T>*> node;
    string filename;
public:
    heaps(string _filename) {
        filename = _filename;
    }
    void push(T d1, T d2, T d3)
    {
        int size = node.size();
        if (size == 0)
        {
            node.push_back(new datos<T>(d1, d2, d3));
        }
        else
        {
            node.push_back(new datos<T>(d1, d2, d3));
            for (int i = size / 2 - 1; i >= 0; i--)
            {
                heapify(i);
            }
        }
    }
    void deleteNode(int num)
    {
        int size = node.size();
        int i;
        for (i = 0; i < size; i++)
        {
            if (num == node[i])
                break;
        }
        swap(node[i], node[size - 1]);

        node.pop_back()
            for (int i = size / 2 - 1; i >= 0; i--)
            {
                heapify(i);
            }
    }
    void heapify(int i)
    {
        int size = node.size();
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < size && node[l] > node[largest])
            largest = l;
        if (r < size && node[r] > node[largest])
            largest = r;

        if (largest != i)
        {
            swap(node[i], node[largest]);
            heapify(largest);
        }
    }
    void swap(datos<T>* a, datos<T>* b)
    {
        datos<T> temp = *b;
        *b = *a;
        *a = temp;
    }
    void showAll()
    {
        for (int i = 0; i < node.size(); ++i) {
            cout << node[i]->data1 << " , " << node[i]->data2 << " , " << node[i]->data3 << ", \n";
        }
        cout << "\n";
    }
    string getCSV() { return filename; }
    int getSize() { return node->size(); }
};