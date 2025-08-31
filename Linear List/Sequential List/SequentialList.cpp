#include <iostream>
using std::cin;
using std::cout;

class SequentialList {
public:
    SequentialList(int max_size) : max_size(max_size), length(0) {
        this->list = new int[max_size];
    }

    ~SequentialList() {
        delete[] this->list;
    }

    bool insertElement(int position, int value) {
        if (position < 0 || position > this->length || this->length >= this->max_size )
            return false;

        for (int i = this->length; i >= position; --i) {
            this->list[i] = this->list[i - 1];
        }
        this->list[position] = value;
        ++this->length;

        return true;
    }

    bool deleteElement(int position) {
        if (position < 0 || position >= this->length)
            return false;

        for (int i = position + 1; i < this->length; ++i) {
            this->list[i - 1] = this->list[i];
        }
        --this->length;

        return true;
    }

    int getElement(int position) {
        return list[position];
    }

    int getLength() {
        return this->length;
    }

    bool expandList(int new_size) {
        if (new_size < this->max_size)
            return false;

        int *new_list = new int[new_size];
        for (int i = 0; i < max_size; ++i) {
            new_list[i] = this->list[i];
        }
        delete[] this->list;
        this->list = new_list;
        this->max_size = new_size;

        return true;
    }

private:
    int max_size;
    int length;
    int *list;
};

int main() {
    SequentialList sequentialList(10);

    for (int i = 0; i < 10; ++i)
        sequentialList.insertElement(i, i);
    sequentialList.expandList(11);
    sequentialList.deleteElement(8);

    cout << sequentialList.getElement(8) << '\n';
    cout << sequentialList.getLength() << '\n';

    return 0;
}