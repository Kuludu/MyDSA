#ifndef MyStack_H_
#define MyStack_H_
namespace MyStackNamespace {
    template <class T>
    struct Element{
        T value;
        Element* prev;
    };
    
    template <class T>
    class MyStack {
        public:
            const unsigned int MAX_SIZE = 4294967295;

            MyStack();
            ~MyStack();
            unsigned int size() const;
            bool isempty() const;
            void push(const T &);
            bool pop();
            T top() const;
        private:
            unsigned int stack_size;
            Element<T> *root_element, *top_element;
    };
}
#endif