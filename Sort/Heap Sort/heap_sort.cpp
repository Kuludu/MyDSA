#include <bits/stdc++.h>
using namespace std;

void build_heap(vector<int> &heap, int root_index, int length) {
    int left_child = root_index * 2 + 1;
    int right_child = root_index * 2 + 2;
    int max_index = root_index;

    if (left_child < length && heap[left_child] > heap[max_index])
        max_index = left_child;
    if (right_child < length && heap[right_child] > heap[max_index])
        max_index = right_child;

    if (max_index != root_index) {
        swap(heap[max_index], heap[root_index]);
        build_heap(heap, max_index, length);
    }
}

void heap_sort(vector<int> &arr, int size) {
    for (int i = size / 2 - 1; i >= 0; --i) {
        build_heap(arr, i, size);
    }

    for (int i = size - 1; i; --i) {
        swap(arr[0], arr[i]);
        build_heap(arr, 0, i);
    }
} 

int main() {
    vector<int> to_be_sorted = {1, 3, 2, 100, 23, 46, 99};

    heap_sort(to_be_sorted, to_be_sorted.size());

    for (auto x : to_be_sorted) {
        cout << x << endl;
    }

    return 0;
}