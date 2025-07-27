#include <variant>
#include <vector>
#include <stdexcept>
#include <type_traits>

using VariantType = std::variant<int, double, std::string>;

class VariantVector {
public:
    template<typename T>
    int push_back(const T& value) {
        static_assert(std::is_same<T, int>::value || std::is_same<T, double>::value || std::is_same<T, std::string>::value, 
                      "Type must be int, double or std::string");
        data.push_back(VariantType(value));
        return static_cast<int>(data.size() - 1);
    }
    
    int push_back() {
        data.push_back(VariantType());
        return static_cast<int>(data.size() - 1);
    }
    
    void pop() {
        if (data.empty()) {
            throw std::runtime_error("Cannot pop from empty vector");
        }
        data.pop_back();
    }
    
    VariantType& operator[](size_t index) {
        if (index >= data.size()) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }
    
    const VariantType& operator[](size_t index) const {
        if (index >= data.size()) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }
    
    size_t size() const {
        return data.size();
    }
    
    bool empty() const {
        return data.empty();
    }
    
    void clear() {
        data.clear();
    }

private:
    std::vector<VariantType> data;
};