#ifndef MyQueue_H_
#define MyQueue_H_

#ifndef _GLIBCXX_MEMORY
#include <memory>
#endif

namespace MyQueueNamespace {
    template<class T>
    struct Element {
        T value;
        std::shared_ptr<Element> next =  nullptr;
    };

    class bad_pop : public std::exception {
    public:
        const std::string what() {
            return "Can't pop element from an empty queue.";
        }
    };
    
    template<class T>
    class MyQueue {
    public:
        MyQueue();
        void push(const T &);
        bool pop();
        T front();
        T back();
    private:
        std::shared_ptr<Element<T>> front_element, back_element;
    protected:
        unsigned int queue_size;
    };

    template<class T>
    class MyBetterQueue : public MyQueue<T> {
    public:
        unsigned int size() const;
        bool isempty() const;
    private:
        using MyQueue<T>::queue_size;
    };

    template<class T>
    MyQueue<T>::MyQueue() {
        front_element = back_element;
    }

    template<class T>
    void MyQueue<T>::push(const T &x) {
        std::shared_ptr<Element<T>> push_element(new Element<T>);
        push_element->value = x;
        if ( queue_size <= 0 )
            front_element = back_element = push_element;
        else if (queue_size == 1) {
            back_element = push_element;
            front_element->next = push_element;
        } else {
            back_element->next = push_element;
            back_element = push_element;
        }

        ++queue_size;
    }

    template<class T>
    bool MyQueue<T>::pop() {
        try {
            if ( queue_size <= 0 )
                throw bad_pop();

            auto next_element = front_element->next;
            front_element = next_element;
        } catch(bad_pop & e) {
            std::cerr << e.what() << std::endl;
            return false;
        }

        --queue_size;
        return true;
    }

    template<class T>
    T MyQueue<T>::front() {
        if ( queue_size )
            return front_element->value;
        
        abort();
    }

    template<class T>
    T MyQueue<T>::back() {
        if ( queue_size )
            return back_element->value;

        abort();
    }

    template<class T>
    unsigned int MyBetterQueue<T>::size() const {
        return queue_size;
    }

    template<class T>
    bool MyBetterQueue<T>::isempty() const {
        return queue_size <= 0;
    }

    template<class T> 
    MyBetterQueue<T> & operator<<(MyBetterQueue<T> &bq, const T &x) {
        bq.push(x); 
        
        return bq;
    }
}
#endif