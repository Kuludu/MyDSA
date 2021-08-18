#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &a, vector<int> &b, int left, int middle, int right) {
    int p = 0, i = left, j = middle + 1;
    while (p < b.size()) {
        if (i <= middle && j <= right ) {
            if (a[i] < a[j]) {
                b[p++] = a[i++];
            } else {
                b[p++] = a[j++];
            }
        } else {
            if (i <= middle) {
                b[p++] = a[i++];
            } else {
                b[p++] = a[j++];
            }
        }
    }

    p = 0;
    while (p < b.size()) {
        a[left + p] = b[p];
        ++p;
    }
}

void merge_sort(vector<int> &a, int left, int right) {
    if (left < right) {
        int middle = (left + right) >> 1;
        merge_sort(a, left, middle);
        merge_sort(a, middle + 1, right);
        vector<int> b(right - left + 1);
        merge(a, b, left, middle, right);
    }
}

int main() {
    vector<int> to_be_sorted = {1, 3, 2, 100, 23, 46, 99};

    merge_sort(to_be_sorted, 0, 6);

    for (auto x : to_be_sorted) {
        cout << x << endl;
    }

    return 0;
}