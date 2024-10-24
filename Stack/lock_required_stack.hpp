#pragma once

#include <mutex>

namespace thread_safe {
    template<typename T>
    struct Node {
        T data;
        Node* next;
        Node(const T& data) : data(data), next(nullptr) {}
    };

    template<typename T>
    class Stack {
        mutable std::mutex mtx;
        Node<T>* head;
    public:
        Stack() {
            head = nullptr;
        }

        void push(const T& data) {
            std::unique_lock<std::mutex> lock(mtx);
            Node<T>* new_node = new Node<T>(data);
            new_node->next = head;
            head = new_node;
        }

        T top() const {
            std::unique_lock<std::mutex> lock(mtx);
            Node<T>* top_node = head;
            if (top_node) {
                return top_node->data;
            }
                
            throw std::runtime_error("Stack is empty.");
        }

        void pop() {
            std::unique_lock<std::mutex> lock(mtx);
            Node<T>* top_node = head;
            if (top_node) {
                Node<T>* next_node = top_node->next;
                head = next_node;
                delete top_node;

                return;
            }
            
            throw std::runtime_error("Stack is empty.");
        }

        bool is_empty() const noexcept {
            std::unique_lock<std::mutex> lock(mtx);

            return head == nullptr;
        }
    };
}
