#include <iostream>
#include <memory>

// Interface of Component
class Component {
public:
    virtual void operation() = 0;
};

// Concrete Component
class ConcreteComponent : public Component {
public:
    void operation() override {
        std::cout << "Base operation." << std::endl;
    }
};

// Decorator of Component
class Decorator : public Component {
protected:
    std::unique_ptr<Component> component;

public:
    Decorator(std::unique_ptr<Component> component) : component(std::move(component)) {}
    void operation() override {
        component->operation();
    }
};

// ConcreteDecorator of Component
class ConcreteDecoratorA : public Decorator {
public:
    ConcreteDecoratorA(std::unique_ptr<Component> component) : Decorator(std::move(component)) {}
    void operation() override {
        Decorator::operation();
        this->added_behavior();
    }

private:
    void added_behavior() {
        std::cout << "Operation A." << std::endl;
    }
};

// ConcreteDecorator of Component
class ConcreteDecoratorB : public Decorator {
public:
    ConcreteDecoratorB(std::unique_ptr<Component> component) : Decorator(std::move(component)) {}
    void operation() override {
        Decorator::operation();
        this->added_behavior();
    }

private:
    void added_behavior() {
        std::cout << "Operation B" << std::endl;
    }
};

int main() {
    auto component = std::make_unique<ConcreteComponent>();
    auto decoratorA = std::make_unique<ConcreteDecoratorA>(std::move(component));
    auto decoratorB = std::make_unique<ConcreteDecoratorB>(std::move(decoratorA));
    decoratorB->operation();

    return 0;
}
