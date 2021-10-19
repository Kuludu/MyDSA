#include <bits/stdc++.h>
using namespace std;

string lp(string source) {
    int length = source.length();
    if (length < 2) 
        return source;

    vector<vector<int>> dp(length, vector<int>(length, 0));
    int max_length = 1;
    int begin_position = 0;

    for (int i = 0; i < length; ++i) {
        dp[i][i] = 1;
    }

    for (int current_length = 2; current_length <= length; ++ current_length) {
        for (int left = 0; left + current_length - 1 < length; ++left) {
            int right = left + current_length - 1;

            if (source[left] == source[right]) {
                if (current_length <= 2) {
                    dp[left][right] = 1;
                } else {
                    dp[left][right] = dp[left + 1][right - 1];
                }
            }

            if (dp[left][right] && current_length > max_length) {
                max_length = current_length;
                begin_position = left;
            }
        }
    }

    return source.substr(begin_position, max_length);
}

int main() {
    string source = "babad";

    cout << lp(source) << endl;

    return 0;
}