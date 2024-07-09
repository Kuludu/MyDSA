#include <iostream>
#include <mutex>

class Singleton {
protected:
    Singleton() = default; // default constructor
    
    Singleton(const Singleton&) = delete; // delete copy constructor
    Singleton& operator=(const Singleton&) = delete; // delete copy assignment operator

    Singleton(const Singleton&&) = delete; // delete move constructor
    Singleton& operator=(const Singleton&&) = delete; // delete move assignment operator
};

class ConcreteSingleton final: public Singleton {
private:
    ConcreteSingleton() {
        static std::mutex mtx;
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << "ConcreteSingleton created." << std::endl;
    }
public:
    static ConcreteSingleton* getInstance() {
        static ConcreteSingleton instance;
        return &instance;
    }
};

int main() {
    Singleton* concreteSingleton_1 = ConcreteSingleton::getInstance();
    Singleton* concreteSingleton_2 = ConcreteSingleton::getInstance();
    std::cout << "ConcreteSingleton1: " << concreteSingleton_1 << std::endl;
    std::cout << "ConcreteSingleton2: " << concreteSingleton_2 << std::endl;
    
    return 0;
}