#ifndef LIST_H_
#define LIST_H_

template<class T>
class List {
public:
    virtual bool insertElement(T, int) = 0;

    virtual bool deleteElement(int) = 0;

    virtual T getElement(int) = 0;

    virtual int getLength() = 0;
};

#endif