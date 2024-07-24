#include <vector>
#include <queue>

namespace TopoSort {
    using std::vector;

    inline namespace Kahan {
        using std::queue;
        class Sort {
        private:
            vector<vector<int>> G;
            vector<int> in_degree;
        public:
            Sort(vector<vector<int>>& g) : G(g) {
                in_degree.resize(g.size(), 0);
                for (int i = 0; i < g.size(); ++i)
                    in_degree[i] = g[i].size();
            }

            bool topo_sort() {
                vector<int> L;
                queue<int> S;

                for (int i = 0; i < G.size(); ++i)
                    if (in_degree[i] == 0)
                        S.push(i);

                while (!S.empty()) { 
                    int u = S.front();
                    S.pop();
                    L.push_back(u);
                    for (auto v : G[u])
                        if (--in_degree[v] == 0)
                            S.push(v);
                }

                if (L.size() == G.size())
                    return true;
                else
                    return false;
            }
        };
    }

    namespace DFS {
        class Sort {
        private:
            vector<vector<int>> G;
            Sort(vector<vector<int>>& g) : G(g) {}
        };
    }
}
