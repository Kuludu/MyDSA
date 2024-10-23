#pragma once

#include <atomic>
#include <stdexcept>

template<typename T>
struct Node {
    T data;
    Node* next;
    Node(const T& data) : data(data), next(nullptr) {}
};

template<typename T>
class Stack {
    std::atomic<Node<T>*> head;
public:
    Stack() {
        head = nullptr;
    }

    void push(const T& data) {
        Node<T>* new_node = new Node<T>(data);
        new_node->next = head.load(std::memory_order_relaxed);
        while (!head.compare_exchange_weak(new_node->next, new_node, std::memory_order_release, std::memory_order_relaxed));
    }

    T top() const {
        Node<T>* top_node = head.load(std::memory_order_acquire);
        if (top_node) {
            return top_node->data;
        }
            
        throw std::runtime_error("Stack is empty.");
    }

    void pop() {
        Node<T>* top_node = head.load(std::memory_order_relaxed);
        while (top_node) {
            Node<T>* next_node = top_node->next;
            if (head.compare_exchange_weak(top_node, next_node, std::memory_order_release, std::memory_order_relaxed)) {
                delete top_node;
                return;
            }
        }

        throw std::runtime_error("Stack is empty.");
    }

    bool is_empty() const noexcept {
        return head.load(std::memory_order_acquire) == nullptr;
    }
};