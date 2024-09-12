#ifndef LFU_H_
#define LFU_H_

#include <unordered_map>
#include <iostream>
#include <list>
#include "AbstractMemoryDeivce.hpp"

using namespace SimuatedMemory;

class LFUMemoryControl final : public AbstractMemeoryDevice {
    class DoubleLinkedLFUMemoryBlock final : public DoubleLinkedMemoryBlock {
    public:
        int frequency;
        DoubleLinkedLFUMemoryBlock(int key, int value, int frequency) 
            : DoubleLinkedMemoryBlock(key, value), frequency(frequency) {}
    };

    int size;
    int min_freq; 
    std::unordered_map<int, DoubleLinkedLFUMemoryBlock*> key_table;
    std::unordered_map<int, std::list<DoubleLinkedLFUMemoryBlock*>> freq_table;

    void updateFrequency(DoubleLinkedLFUMemoryBlock* block) {
        int freq = block->frequency;
        freq_table[freq].remove(block);

        if (freq_table[freq].empty() && min_freq == freq) {
            freq_table.erase(freq);
            min_freq++;
        }

        block->frequency++;
        freq_table[block->frequency].push_back(block);
    }
public:
    LFUMemoryControl(int capacity) : AbstractMemeoryDevice(capacity) {}

    void get(int key) override {
        if (key_table.find(key) == key_table.end()) {
            std::cout << "Block not found in cache." << std::endl;

            return;
        }

        DoubleLinkedLFUMemoryBlock* block = key_table[key];
        std::cout << "Block found in cache, the value is " << block->value << "." << std::endl;
        updateFrequency(block);
    }

    void put(int key, int&& value) override {
        if (MAX_CAP == 0) {
            return;
        }

        if (key_table.find(key) != key_table.end()) {
            DoubleLinkedLFUMemoryBlock* block = key_table[key];
            std::cout << "Block found in cache, updating value." << std::endl;
            block->value = value;
            updateFrequency(block);

            return;
        }

        if (size == MAX_CAP) {
            DoubleLinkedLFUMemoryBlock* evict_block = freq_table[min_freq].front();
            freq_table[min_freq].pop_front();
            key_table.erase(evict_block->key);
            std::cout << "Reaching maximum capacity, evicting." << std::endl;
            delete evict_block;
            size--;
        }

        DoubleLinkedLFUMemoryBlock* new_block = new DoubleLinkedLFUMemoryBlock(key, value, 1);
        std::cout << "Setting block " << key << "." << std::endl;
        key_table[key] = new_block;
        freq_table[1].push_back(new_block);
        min_freq = 1;
        size++;
    }
};

#endif