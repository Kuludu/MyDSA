#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> G(n + 1, vector<int>(n + 1, INT_MAX));
    vector<int> dist(n + 1, INT_MAX);
    vector<bool> vis(n + 1);

    int u, v, w;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        G[u][v] = min(G[u][v], w);
        G[v][u] = min(G[u][v], w);
    }

    int ans = 0, current = 1;
    dist[1] = 0;
    for (int t = 0; t < n; ++t) {
        int minn = INT_MAX;
        for (int i = 1; i <= n; ++i)
            if (!vis[i] && minn > dist[i]) {
                minn = dist[i];
                current = i;
            }

        vis[current] = true;
        ans += minn;

        for (int i = 1; i <= n; ++i) 
            if (!vis[i] && G[current][i] != INT_MAX && G[current][i] < dist[i])
                dist[i] = G[current][i];
    }

    cout << ans << endl;

    return 0;
}