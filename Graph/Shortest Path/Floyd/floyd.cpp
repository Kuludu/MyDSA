#include <bits/stdc++.h>
using namespace std;

void floyd(vector<vector<long long>> &G) {
    int n = G.size();

    for (int k = 0; k < n; ++k) 
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
}

int main() {
    int u = 0;
    int v = 3;
    vector<vector<long long>> G(4, vector<long long>(4, INT_MAX));
    G[0][1] = 1;
    G[1][2] = 2;
    G[1][3] = 10;
    G[2][3] = 3;

    floyd(G);

    cout << G[u][v] << endl;

    return 0;
}