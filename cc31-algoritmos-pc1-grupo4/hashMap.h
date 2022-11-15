#pragma once

#include"Lib.h"
#include"hashList.h"
#include"Node.h"

template<class T>
class hashMap {
private:
    static const int nRows = 999997;
    hashList<T>* rows;
    string filename;
    int size;
public:
    hashMap(string _filename) {
        rows = new hashList<T>[nRows];
        filename = _filename;
        size = 0;
    }
    ~hashMap() {}

    int hash(int key) {
        return key % nRows;
    }

    void push(int id, string name, string author, string album) {
        int hashCode = hash(id);
        rows[hashCode].push(id, name, author, album);
        size++;
    }

    void remove(int hashKey) {
        int listPos = hash(hashKey);
        rows[listPos].remove(hashKey);
    }

    void search(string hashKey) {
        int listPos = hash(hashKey);
        cout << listPos;
        rows[listPos].search(hashKey) ? cout << "Found\n" : cout << "Not found\n";
    }

    void show() {
        for (int i = 0; i < nRows; i++) {
            cout << "-------------ROW " << i << "-------------\n";
            rows[i].showAll();
        }

        cout << "TOTAL: "<<size<<"\n";
    }

    string getCSV() { return filename; }
};