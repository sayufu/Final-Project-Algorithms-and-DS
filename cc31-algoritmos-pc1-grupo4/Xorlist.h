#pragma once
#include"Node.h"

template<class var>
class Xorlist {
private:
	Node<var>* head;
    string filename;
public:
    Xorlist(string _filename) {
        head = NULL;
        filename = _filename;
    }
    ~Xorlist() {
        if (head != NULL)
        {
            Node<var>* head_next = XOR(NULL, head->next);
            while (head_next != NULL)
            {
                Node<var>* temp = head;
                head = head_next;
                head_next = XOR(temp, head->npx);
                delete temp; // delete previous node of new head
            }
            delete head;
            head = NULL;
        }
    }
    void push(var data1, var data2, var data3){
    if (head == NULL)
    {
        head = new Node<var>(data1, data2, data3);
    }
    else
    {
        Node<var>* new_node = new Node<var>(data1, data2, data3);
        new_node->next = XOR(NULL, head);
        head->next = XOR(new_node, head->next);
        head = new_node;
    }
    }
    void showAll() {
        if (head == NULL)
        {
            throw runtime_error("head is NULL");
        }

        Node<var>* prev = NULL;
        Node<var>* temp = head;

        while (temp != NULL)
        {
            cout << "["<<temp->data1 << " , " << temp->data2 << " , " << temp->data3 << "]\n";
            Node<var>* next = XOR(prev, temp->next);
            prev = temp;
            temp = next;
        }

        cout << endl;

        while (prev != NULL)
        {
            cout << "["<<prev->data1 << " , " << prev->data2 << " , " << prev->data3 << "]\n";
            Node<var>* next = XOR(temp, prev->next);
            temp = prev;
            prev = next;
        }
    }
    Node<var>* XOR(Node<var>* x, Node<var>* y) {
        return (Node<var>*)(uintptr_t(x) ^ uintptr_t(y));
    }
    string getCSV() { return filename; }
};
