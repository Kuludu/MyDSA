#include <memory>
#include "lru.hpp"
#include "lfu.hpp"

int main(int argc, char* argv[]) {
    auto lruMemoryControl = std::make_shared<LRUMemoryControl>(2);
    
    std::cout << "LRU Memory Control Test" << std::endl;
    lruMemoryControl->put(1, std::move(1));
    lruMemoryControl->put(2, std::move(2));
    lruMemoryControl->get(1);
    lruMemoryControl->put(3, std::move(3));
    lruMemoryControl->get(2);
    lruMemoryControl->put(4, std::move(4));
    lruMemoryControl->get(1);
    lruMemoryControl->get(3);
    lruMemoryControl->get(4);
    lruMemoryControl->put(4, std::move(3));
    lruMemoryControl->get(4);

    auto lfuMemoryControl = std::make_shared<LFUMemoryControl>(2);

    std::cout << "LFU Memory Control Test" << std::endl;
    lfuMemoryControl->put(1, 1);
    lfuMemoryControl->put(2, 2);
    lfuMemoryControl->get(1);
    lfuMemoryControl->put(3, 3);
    lfuMemoryControl->get(2);
    lfuMemoryControl->get(3);
    lfuMemoryControl->put(4, 4);
    lfuMemoryControl->get(1);
    lfuMemoryControl->get(3);
    lfuMemoryControl->get(4);

    return 0;
}