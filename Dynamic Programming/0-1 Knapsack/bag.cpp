#include <bits/stdc++.h>
using namespace std;

int bag(vector<int> &c, vector<int> &w, int max_capacity) {
    int n = c.size();
    vector<int> dp(max_capacity + 1);

    for (int i = 0; i < n; ++i)
        for (int j = max_capacity; j >= c[i]; --j) 
            dp[j] = max(dp[j], dp[j - c[i]] + w[i]);
        
    return dp.back();
}

int main() {
    vector<int> capacities = {1, 2, 3, 4, 5};
    vector<int> weights = {6, 7, 8, 9, 10};

    cout << bag(capacities, weights, 10) << endl;

    return 0;
}