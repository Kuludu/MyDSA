#include "BinaryOperator.cpp"
#include <type_traits>

template<typename U, typename V>
class Divide : public BinaryOperator<U, V> {
private:
    using BinaryOperator<U, V>::element_a;
    using BinaryOperator<U, V>::element_b;
public:
    Divide(U a, V b) : BinaryOperator<U, V>(a, b) {};
    auto execute() -> decltype(element_a / element_b) {
        if (std::is_integral_v<V>) {
            if (element_b == 0) {
                throw std::runtime_error("Cannot divide by zero.");
            }
        } else if (std::is_floating_point_v<V>) {
            if (element_b == 0.0) {
                throw std::runtime_error("Cannot divide by zero.");
            }
        } else {
            throw std::runtime_error("Invalid type for division.");
        }

        return element_a / element_b;
    }
};