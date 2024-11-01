template <typename T>
class UniquePointer {
    T* _ptr;
public:
    explicit UniquePointer(T* ptr = nullptr) {
        _ptr = ptr;
    }

    // Copy constructor
    UniquePointer(const UniquePointer<T>& other) = delete;

    // Move constructor
    UniquePointer(UniquePointer<T>&& other) noexcept : _ptr(other._ptr) {
        other._ptr = nullptr;
    }

    // Copy assignment operator
    UniquePointer& operator=(const UniquePointer<T>& other) = delete;

    // Move assignment operator
    UniquePointer& operator=(UniquePointer<T>&& other) noexcept {
        _ptr = other._ptr;
        other._ptr = nullptr;

        return *this;
    }

    T& operator*() const noexcept {
        return *_ptr;
    }

    T* operator->() const noexcept {
        return _ptr;
    }

    T* get() const noexcept {
        return _ptr;
    }

    virtual ~UniquePointer() {
        delete this->_ptr;
    }
};