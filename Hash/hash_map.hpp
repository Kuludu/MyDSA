#pragma once

#include <vector>
#include <list>

template<typename K, typename V>
class HashMap {
    std::vector<std::list<std::pair<K, V>>> map;
    int capacity;
public:
    HashMap(int size) {
        capacity = size;
        map.resize(size);
    }

    int hash(K key) {
        return key % capacity;
    }

    void insert(K key, V value) {
        int index = hash(key);
        map[index].push_back({key, value});
    }

    V get(K key) {
        int index = hash(key);
        for (auto& it : map[index]) {
            if (it.first == key) {
                return it.second;
            }
        }
        throw std::runtime_error("Key not found!");
    }

    void remove(K key) {
        int index = hash(key);
        for (auto it = map[index].begin(); it != map[index].end(); ++it) {
            if (it->first == key) {
                map[index].erase(it);
                return;
            }
        }
        throw std::runtime_error("Key not found!");
    }
};