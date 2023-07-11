#include <iostream>
#include "../List.hpp"

using std::cout;

template<class T>
class DoubleLinkedList : private List<T> {
public:
    DoubleLinkedList() {
        this->length = 0;
        this->root = nullptr;
    }

    ~DoubleLinkedList() {
        Node *next, *current;
        current = this->root;
        if (current == nullptr)
            return;
        next = this->root->next;
        while (next != nullptr) {
            delete current;
            current = next;
            next = current->next;
        }
        delete current;
    }

    bool isEmpty() {
        return this->length == 0;
    }

    bool insertElement(T value, int position) {
        if (position > this->length)
            return false;

        Node *to_be_inserted = new Node();
        to_be_inserted->value = value;
        to_be_inserted->prev = nullptr;
        to_be_inserted->next = nullptr;

        if (this->length == 0) 
            this->root = to_be_inserted;
        else {
            Node *current_ptr = this->root;
            for (int i = 0; i < position - 1; ++i) 
                current_ptr = current_ptr->next;

            to_be_inserted->next = current_ptr->next;
            current_ptr->next = to_be_inserted;
            to_be_inserted->prev = current_ptr;
        }

        if (to_be_inserted->next != nullptr)
            to_be_inserted->next->prev = to_be_inserted;

        ++this->length;

        return true;
    }

    bool appendElement(T value) {
        Node *current_ptr = this->root;

        Node *to_be_appened = new Node();
        to_be_appened->value = value;
        to_be_appened->next = nullptr;

        if (current_ptr == nullptr) 
            current_ptr = to_be_appened;
        else {
            while (current_ptr->next != nullptr)
                current_ptr = current_ptr->next;

            current_ptr->next = to_be_appened;
            to_be_appened->prev = current_ptr;
        }

        ++this->length;

        return true;
    }

    bool deleteElement(int position) {
        if (position >= this->length)
            return false;

        Node *to_be_deleted = this->root;
        for (int i = 0; i < position; ++i) {
            to_be_deleted = to_be_deleted->next;
        }
        if (to_be_deleted->next != nullptr)
            to_be_deleted->next->prev = to_be_deleted->prev;
        if (to_be_deleted->prev != nullptr)
            to_be_deleted->prev->next = to_be_deleted->next;
        delete to_be_deleted;

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
    doubleLinkedList.appendElement(4);
    doubleLinkedList.deleteElement(10);
    doubleLinkedList.deleteElement(3);
    cout << doubleLinkedList.getElement(2) << '\n';
    cout << doubleLinkedList.getLength() << '\n';
    if (doubleLinkedList.isEmpty())
        cout << "List is empty.\n";
    else
        cout << "List in not empty.\n";

    return 0;
}