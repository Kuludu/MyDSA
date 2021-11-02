#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
const int INF = 0x3F3F3F3F;

int start_node, end_node, node_num;
int dist[MAXN];
vector<pair<int, int>> G[MAXN];

void dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < node_num; ++i) {
        dist[i] = INF;
    }
    dist[start_node] = 0;
    pq.push({0, start_node});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
        for (auto &e : G[u]) {
            int v = e.second;
            int w = e.first;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    start_node = 0;
    end_node = 3;
    node_num = 4;
    G[0].push_back({1, 1});
    G[1].push_back({1, 2});
    G[1].push_back({3, 3});
    G[2].push_back({1, 3});

    dijkstra();

    cout << dist[end_node] << endl;

    return 0;
}