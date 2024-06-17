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
        head = tail = nullptr;
    }

    void get(int block_id) override {
        std::cout << "Getting block " << block_id << "." << std::endl;
        if (cache.find(block_id) != cache.end()) {

            std::cout << "Cache found, the value is " << cache[block_id]->value << "." << std::endl;
            return;
        }

        std::cout << "Cache not found." << std::endl;
    }

    void put(int key, int&& value) override {
        std::cout << "Setting block " << key << "." << std::endl;

        if (cache.find(key) != cache.end()) {
            std::cout << "Block found in cache, updating value." << std::endl;
            this->cache[key]->value = value;
            this->move(key);
        } else {
            std::cout << "Block not found in cache, appending." << std::endl;
            std::shared_ptr<DoubleLinkedMemoryBlock> new_block = std::make_shared<DoubleLinkedMemoryBlock>(key, value);
            this->cache[key] = new_block;
            this->append(new_block);

            if (cache.size() > MAX_CAP) {
                std::cout << "Reaching maximum capacity, evicting." << std::endl;
                int key = this->head->key;
                this->head = this->head->next;
                this->head->prev = nullptr;
                cache.erase(key);
            }
        }
    }
private:
    std::unordered_map<int, std::shared_ptr<SimuatedMemory::DoubleLinkedMemoryBlock>> cache;
    std::shared_ptr<SimuatedMemory::DoubleLinkedMemoryBlock> head, tail;

    void move(int key) {
        auto block = this->cache[key];
        if (this->head == block) {
            if (this->head->next != nullptr) {
                this->head = this->head->next;
                this->head->prev = nullptr;

                this->tail->next = block;
                block->prev = this->tail;
                block->next = nullptr;
            }
        } else {
            block->prev->next = block->next;
            block->next->prev = block->prev;

            this->tail->next = block;
            block->prev = this->tail;
            block->next = nullptr;
            this->tail = block;
        }
    }

    void append(std::shared_ptr<DoubleLinkedMemoryBlock> block) {
        if (this->head == nullptr) {
            this->head = this->tail = block;
        } else {
            this->tail->next = block;
            block->prev = this->tail;
            this->tail = block;
        }
    }
};

#endif