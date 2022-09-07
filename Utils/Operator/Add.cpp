#include "BinaryOperator.cpp"

template<typename U, typename V>
class Add : public BinaryOperator<U, V> {
private:
    using BinaryOperator<U, V>::element_a;
    using BinaryOperator<U, V>::element_b;
public:
    Add(U a, V b) : BinaryOperator<U, V>(a, b) {};
    auto execute() -> decltype(element_a + element_b) {
        return element_a + element_b;
    }
};