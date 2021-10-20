#include <bits/stdc++.h>
using namespace std;

int lis(vector<int> &nums) {
    int n = nums.size();
    if (n == 0)
        return 0;

    vector<int> dp(n);

    for (int i = 0; i < n; ++i) {
        dp[i] = 1;
        for (int j = 0; j < i; ++j) 
            if (nums[j] < nums[i])
                dp[i] = max(dp[i], dp[j] + 1);
    }

    return *max_element(dp.begin(), dp.end());
}

int main() { 
    vector<int> sequence = {1, 2, 3, 6, 4, 100, 32, 77, 1022};

    cout << lis(sequence) << endl;
     
    return 0;
}