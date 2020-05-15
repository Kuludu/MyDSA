#ifndef MyQueue_H_
#define MyQueue_H_
namespace MyQueueNamespace {
    template<class T>
    struct Element {
        T value;
        Element* next = nullptr;
    };
    
    template<class T>
    class MyQueue {
    public:
        MyQueue();
        ~MyQueue();
        bool push(const T &);
        bool pop();
        T front();
        T back();
    private:
        Element<T> *front_element, *back_element;
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
    MyQueue<T>::~MyQueue() {
        try {
            if ( queue_size ) {
                while ( front_element != back_element ) {
                        auto next_element = front_element->next;
                        delete front_element;
                        front_element = next_element;   
                }

                delete front_element;
            }
        } catch(const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }

    template<class T>
    bool MyQueue<T>::push(const T &x) {
        try {
            Element<T> *push_element = new Element<T>;
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
        } catch(const std::exception& e) {
            std::cerr << e.what() << std::endl;
            return false;
        }

        ++queue_size;
        return true;
    }

    template<class T>
    bool MyQueue<T>::pop() {
        try {
            if ( queue_size == 2 ) {
                delete front_element;
                front_element = back_element;
            } else if ( queue_size == 1 ) {
                delete front_element;
            } else {
                auto next_element = front_element->next;
                delete front_element;
                front_element = next_element;
            }
        } catch(const std::exception& e) {
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