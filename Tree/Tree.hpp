#ifndef MyTree_H_
#define MyTree_H_

#ifndef _GLIBCXX_MEMORY
#include <memory>
#endif
#ifndef _GLIBCXX_VECTOR
#include <vector>
#endif
#ifndef _GLIBCXX_IOSTREAM
#include <iostream>
#endif

namespace MyTreeNamespace {
    template<class T>
    struct Node {
        T value;
        std::shared_ptr<Node> left_son, right_son;
    };
    
    template<class T>
    class MyTree {
    public:
        void add_node(std::shared_ptr<Node<T>> &, const T &);
        void in_order_print();
        std::shared_ptr<Node<T>> root;
    private:
        void on_in_order_print(const std::shared_ptr<Node<T>> &);
        void on_print(const std::shared_ptr<Node<T>> &);
        void on_build(std::shared_ptr<Node<T>> &, const T &);
    };

    template<class T>
    void MyTree<T>::add_node(std::shared_ptr<Node<T>> &to_be_added, const T &value) {
        this->on_build(to_be_added, value);
    }

    template<class T>
    void MyTree<T>::in_order_print() {
        this->on_in_order_print(this->root);
        std::cout << std::endl;
    }

    template<class T>
    void MyTree<T>::on_in_order_print(const std::shared_ptr<Node<T>> &node) {
        if (node->left_son) {
            this->on_in_order_print(node->left_son);
        }

        std::cout << node->value << ' ';

        if (node->right_son) {
            this->on_in_order_print(node->right_son);
        }
    }

    template<class T>
    void MyTree<T>::on_build(std::shared_ptr<Node<T>> &node, const T &value) {
        node = std::make_shared<Node<T>>();
        node->value = value;
    }
}

#endif