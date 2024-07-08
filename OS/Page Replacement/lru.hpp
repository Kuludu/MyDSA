#ifndef LRU_H_
#define LRU_H_

#include <unordered_map>
#include <iostream>
#include <list>
#include <queue>
#include "AbstractMemoryDeivce.hpp"

using namespace SimuatedMemory;

class LRUMemoryControl final : public AbstractMemeoryDevice {
public:
    LRUMemoryControl(int max_cap) : AbstractMemeoryDevice(max_cap) {
        this->head = this->tail = nullptr;
    }

    void get(int key) override {
        std::cout << "Getting block " << key << "." << std::endl;

        if (cache.count(key)) {
            DLM *block = cache[key];
            std::cout << "Block found in cache, the value is " << block->value << "." << std::endl;
            this->moveToHead(block);
        } else {
            std::cout << "Block not found in cache." << std::endl;
        }
    }

    void put(int key, int&& value) override {
        std::cout << "Setting block " << key << "." << std::endl;

        if (cache.count(key)) {
            DLM *block = cache[key];
            std::cout << "Block found in cache, updating value." << std::endl;
            block->value = value;
            moveToHead(block);
        } else {
            std::cout << "Block not found in cache, appending." << std::endl;
            if (cache.size() >= MAX_CAP) {
                std::cout << "Reaching maximum capacity, evicting." << std::endl;
                this->removeTail();
            }
            DLM *block = new DLM(key, value);
            cache[key] = block;
            addToHead(block);
        }
    }
private:
    using DLM = SimuatedMemory::DoubleLinkedMemoryBlock;
    std::unordered_map<int, DLM*> cache;
    DLM *head, *tail;

    void addToHead(DLM *x) {
        if (head == nullptr) {
            head = tail = x;
        } else {
            x->next = head;
            head->prev = x;
            head = x;
        }
    }

    void moveToHead(DLM *x) {
        if (x != head) {
            x->prev->next = x->next;
            if (x == this->tail)
                this->tail = x->prev;
            else
                x->next->prev = x->prev;
            x->next = head;
            x->prev = nullptr;
            head->prev = x;
            head = x;
        }
    }

    void removeTail() {
        if (tail != nullptr) {
            DLM *tmp = tail;
            std::cout << "Evicting block " << tmp->key << "." << std::endl;
            tail = tail->prev;
            if (tail != nullptr) {
                tail->next = nullptr;
            } else {
                head = nullptr;
            }
            cache.erase(tmp->key);
            delete tmp;
        }
    }
};

#endif