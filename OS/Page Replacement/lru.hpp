#ifndef LRU_H_
#define LRU_H_

#include <unordered_map>
#include <iostream>
#include <list>
#include <queue>
#include "AbstractMemoryDeivce.hpp"

class LRUMemoryControl final : public AbstractMemeoryDevice {
public:
    LRUMemoryControl(int max_cap) : AbstractMemeoryDevice(max_cap) {}

    void get(int block_id) override {
        std::cout << "Getting block " << block_id << "." << std::endl;
        if (cache.find(block_id) != cache.end()) {
            ++cache[block_id].second;
            recentVisit.push(block_id);

            std::cout << "Cache found, the value is " << cache[block_id].first << "." << std::endl;
            return;
        }

        std::cout << "Cache not found." << std::endl;
    }

    void put(int block_id, int&& value) override {
        std::cout << "Setting block " << block_id << "." << std::endl;

        if (cache.find(block_id) != cache.end()) {
            std::cout << "Block found in cache." << std::endl;
            cache[block_id].first = value;
            ++cache[block_id].second;
            recentVisit.push(block_id);
        } else {
            std::cout << "Block not found in cache, appending." << std::endl;
            cache[block_id].first = value;
            ++cache[block_id].second;
            recentVisit.push(block_id);

            if (cache.size() > MAX_CAP) {
                std::cout << "Reaching maximum capacity, evicting." << std::endl;
                while (!cache.empty()) {
                    int last_unused = recentVisit.front();
                    recentVisit.pop();
                    --cache[last_unused].second;
                    if (cache[last_unused].second == 0) {
                        cache.erase(last_unused);
                        std::cout << last_unused << " evicted" << std::endl;
                        break;
                    }
                }
            }
        }
    }
private:
    std::unordered_map<int, std::pair<int, int>> cache;
    std::queue<int> recentVisit;
};

#endif