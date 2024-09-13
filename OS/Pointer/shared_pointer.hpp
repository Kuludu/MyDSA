template <typename T>
class SharedPointer {
    T* _ptr;
    int* _ref_count;

    void release() {
        if (_ref_count && --(*_ref_count) <= 0) {
            delete _ptr;
            delete _ref_count;
            _ptr = nullptr;
            _ref_count = nullptr;
        }
    }
public:
    explicit SharedPointer(T* ptr = nullptr) {
        if (ptr) {
            _ptr = ptr;
            _ref_count = new int(1);
        } else {
            _ptr = nullptr;
            _ref_count = nullptr;
        }
    }

    // Copy constructor
    SharedPointer(const SharedPointer<T>& other) noexcept : _ptr(other._ptr), _ref_count(other._ref_count) {
        if (_ptr)
            ++(*_ref_count);
    }

    // Move constructor
    SharedPointer(SharedPointer<T>&& other) noexcept : _ptr(other._ptr), _ref_count(other._ref_count) {
        other._ptr = nullptr;
        other._ref_count = nullptr;
    }

    // Copy assignment operator
    SharedPointer& operator=(const SharedPointer<T>& other) noexcept {
        if (this != &other) {
            if (_ptr)
                this->release();

            _ptr = other._ptr;
            _ref_count = other._ref_count;
            if (_ptr)
                ++(*_ref_count);
        }

        return *this;
    }

    // Move assignment operator
    SharedPointer& operator=(SharedPointer<T>&& other) noexcept {
        if (this != &other) {
            this->release();

            _ptr = other._ptr;
            _ref_count = other._ref_count;
            other._ptr = nullptr;
            other._ref_count = nullptr;
        }

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

    int use_count() const noexcept {
        return *_ref_count;
    }

    virtual ~SharedPointer() {
        this->release();
    }
};