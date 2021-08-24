#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int n = 4;
vector<pair<int, pair<int, int>>> edges = {{1, {2, 1}}, {2, {4, 2}}, {3, {4, 3}}, {1, {3, 4}}};
int belong[N];
int ans;

int find(int x) {
    if (belong[x] == x) 
        return x;

    return belong[x] = find(belong[x]);
}

bool compare(const pair<int, pair<int, int>> a, const pair<int, pair<int, int>> b) {
    return a.second.second < b.second.second;
}

int main() {
    sort(edges.begin(), edges.end(), compare);

    for (int i = 1; i <= n; ++i)
        belong[i] = i;

    for (auto edge : edges) {
        int u_belong = find(edge.first);
        int v_belong = find(edge.second.first);

        if (u_belong != v_belong) {
            ans += edge.second.second;
            belong[u_belong] = v_belong;
        }
    }

    cout << ans << endl;

    return 0;
}