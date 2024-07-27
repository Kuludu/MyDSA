template<typename ForwardIterator, typename T>
ForwardIterator lower_bound_search(ForwardIterator first, ForwardIterator last, const T& value) {
    while (first != last) {
        ForwardIterator mid = first + (last - first) / 2;
        if (*mid < value) {
            first = mid + 1;
        } else {
            last = mid;
        }
    }

    return first;
}