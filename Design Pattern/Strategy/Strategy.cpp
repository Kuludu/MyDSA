#include <iostream>

class Strategy {
public:
    virtual void execute() = 0;
};

class ConcreteStrategyA : public Strategy {
public:
    void execute() override {
        std::cout << "Executing strategy A" << std::endl;
    }
};

int main() {
    Strategy* strategy = new ConcreteStrategyA();
    strategy->execute();

    return 0;
}