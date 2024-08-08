#include <bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        for (int j = 0; j < arr.size(); ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }  
        }
    }
} 

int main() {
    vector<int> to_be_sorted = {1, 3, 2, 100, 23, 46, 99};

    bubble_sort(to_be_sorted);

    for (auto& x : to_be_sorted) {
        cout << x << endl;
    }

    return 0;
}