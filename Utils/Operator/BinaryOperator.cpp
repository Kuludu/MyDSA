#pragma once

template<typename U, typename V>
class BinaryOperator {
public:
    BinaryOperator(U a, V b) : element_a(a), element_b(b) {};
    virtual V execute() = 0;
protected:
    U element_a;
    V element_b;
};