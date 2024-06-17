#include <memory>
#include "lru.hpp"

int main(int argc, char** argv) {
    auto lruMemoryControl = std::make_shared<LRUMemoryControl>(4);
    
    lruMemoryControl->put(1, std::move(1));
    lruMemoryControl->put(1, std::move(2));
    lruMemoryControl->put(2, std::move(1));
    lruMemoryControl->put(3, std::move(1));
    lruMemoryControl->get(10);
    lruMemoryControl->put(4, std::move(1));
    lruMemoryControl->put(5, std::move(1));
    lruMemoryControl->get(1);
    lruMemoryControl->get(2);

    return 0;
}