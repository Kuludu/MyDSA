#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &a, int left, int right) {
    int i = left, j = right + 1;
    int x = a[left];
    
    while (true) {
        while (a[++i] < x && i < right);
        while (a[--j] > x);
        if (i >= j)
            break;
        
        swap(a[i], a[j]);
    }

    a[left] = a[j];
    a[j] = x;
    
    return j;
}

void quick_sort(vector<int> &a, int l, int r) {
    if (l < r) {
        int mid = partition(a, l, r);
        quick_sort(a, l, mid - 1);
        quick_sort(a, mid + 1, r);
    }
}

int main() {
    vector<int> to_be_sorted = {9, 10, 1, 99, 108, 46};

    quick_sort(to_be_sorted, 0, 5);

    for ( auto x : to_be_sorted ) {
        cout << x << endl;
    }

    return 0;
}