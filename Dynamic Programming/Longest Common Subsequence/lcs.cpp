#include <bits/stdc++.h>
using namespace std;

int lcs(vector<char> a, vector<char> b) {
    int len_a = a.size();
    int len_b = b.size();

    vector<vector<int>> dp(len_a + 1, vector<int>(len_b + 1, 0));

    for (int i = 1; i <= len_a; ++i)
        for (int j = 1; j <= len_b; ++j) 
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else { 
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }

    return dp[len_a][len_b];
}

int main() { 
    vector<char> sequence_a = {'1', '2', '3', '4', '2', '2'};
    vector<char> sequence_b = {'1', '2', '4', '3', '1', '2'};

    cout << lcs(sequence_a, sequence_b) << endl;
     
    return 0;
}