#include <iostream>
using std::cout;
using std::nullptr_t;

class SingleLinkedList {
public:
    SingleLinkedList() {
        this->head = new Node();
    }

    ~SingleLinkedList() {
        Node *next, *current;
        current = this->head;
        next = this->head->next;
        while (next != nullptr) {
            delete current;
            current = next;
            next = current->next;
        }
        delete current;
    }

    bool insertElement(int position, int value) {
        if (position > this->length)
            return false;

        Node *current = this->head;
        for (int i = 0; i < position; ++i) {
            current = current->next;
        }
        Node *to_be_insert = new Node();
        to_be_insert->value = value;
        to_be_insert->next = current->next;
        current->next = to_be_insert;
        ++this->length;

        return true;
    }

    bool deleteElement(int position) {
        if (position > this->length)
            return false;

        Node *current = this->head;
        for (int i = 0; i < position; ++i) {
            current = current->next;
        }
        Node *next = current->next->next;
        delete current->next;
        current->next = next;

        --this->length;

        return true;
    }

    int getElement(int position) {
        Node *current = head;
        for ( int i = 0; i < position + 1; ++i ) {
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
        int value;
        Node *next;
    }*head;
};

int main() {
    SingleLinkedList singleLinkedList;

    singleLinkedList.insertElement(0, 1);
    singleLinkedList.insertElement(1, 2);
    singleLinkedList.insertElement(2, 3);
    singleLinkedList.deleteElement(1);
    cout << singleLinkedList.getElement(1) << '\n';
    cout << singleLinkedList.getLength() << '\n';

    return 0;
}