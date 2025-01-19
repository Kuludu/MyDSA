#include "BinaryOperator.cpp"
#include <type_traits>
#include <stdexcept>

template<typename U, typename V,
         typename = typename std::enable_if<
            (std::is_integral_v<U> || std::is_floating_point_v<U>) &&
            (std::is_integral_v<V> || std::is_floating_point_v<V>)>::type>
class Divide : public BinaryOperator<U, V> {
private:
    using BinaryOperator<U, V>::element_a;
    using BinaryOperator<U, V>::element_b;
public:
    Divide(U a, V b) : BinaryOperator<U, V>(a, b) {
        if constexpr (std::is_integral_v<V>) {
            if (0 == element_b) {
                throw std::runtime_error("Cannot divide by zero.");
            }
        } else if constexpr (std::is_floating_point_v<V>) {
            if (0.0 == element_b) {
                throw std::runtime_error("Cannot divide by zero.");
            }
        }
    }

    V execute() override {
        return element_a / element_b;
    }
};