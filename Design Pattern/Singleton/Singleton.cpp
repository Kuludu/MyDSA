#include <iostream>
#include <mutex>

class Singleton {
private:
    Singleton() {
        static std::mutex mtx;
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << "Singleton created." << std::endl;
    }

public:
    static Singleton* getInstance() {
        static Singleton instance;
        return &instance;
    }
};

int main() {
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();
    std::cout << "s1: " << s1 << std::endl;
    std::cout << "s2: " << s2 << std::endl;
    
    return 0;
}