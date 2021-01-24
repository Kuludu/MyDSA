#include <iostream>
#include "../List.hpp"

using std::cout;

template<class T>
class DoubleLinkedList : private List<T> {
public:
    DoubleLinkedList() {
        this->root = new Node();
    }

    ~DoubleLinkedList() {
        Node *next, *current;
        next = this->root->next;
        current = this->root;
        while (next != nullptr) {
            delete current;
            current = next;
            next = current->next;
        }
        delete current;
    }

    bool insertElement(T value, int position) {
        if (position > this->length)
            return false;

        Node *current = this->root;
        for (int i = 0; i < position; ++i) {
            current = current->next;
        }
        Node *to_be_insert = new Node();
        to_be_insert->value = value;
        to_be_insert->next = current->next;
        to_be_insert->prev = current;
        current->next = to_be_insert;
        if (to_be_insert->next != nullptr)
            to_be_insert->next->prev = to_be_insert;

        ++this->length;

        return true;
    }

    bool deleteElement(int position) {
        if (position >= this->length)
            return false;

        Node *current = this->root;
        for (int i = 0; i < position; ++i) {
            current = current->next;
        }
        Node *to_be_delete = current->next;
        if (to_be_delete->next != nullptr)
            to_be_delete->next->prev = current;
        current->next = to_be_delete->next;
        delete to_be_delete;

        --this->length;

        return true;
    }

    T getElement(int position) {
        Node *current = this->root;
        for (int i = 0; i < position; ++i) {
            current = current->next;
        }

        return current->value;
    }

    int getLength() {
        return this->length;
    }

private:
    int length;
    struct Node {
        T value;
        Node *prev, *next;
    } *root;
};

int main() {
    DoubleLinkedList<int> doubleLinkedList;

    doubleLinkedList.insertElement(1, 0);
    doubleLinkedList.insertElement(2, 1);
    doubleLinkedList.insertElement(3, 2);
    doubleLinkedList.deleteElement(3);
    cout << doubleLinkedList.getElement(1) << '\n';
    cout << doubleLinkedList.getLength() << '\n';

    return 0;
}