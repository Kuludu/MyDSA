#ifndef _LIBCPP_VECTOR
#include <vector>
#endif

class DisjointSet {
public:
    DisjointSet(int size) {
        this->parent.resize(size);
        for (int i = 0; i < size; ++i) {
            this->parent[i] = i;
        }
        // Initalization of parent vector, each element is its own parent.
    }

    DisjointSet& operator=(const DisjointSet&) = delete;

    int find(int x) noexcept {
        if (this->parent[x] != x) {
            this->parent[x] = this->find(this->parent[x]);
        }
        // Compress, shorten the time for next find operation.
        return this->parent[x];
    }

    void migrate(int p, int q) noexcept {
        this->parent[this->find(p)] = this->find(q);
        // Make the parent of p's root node to be q's root node.
    }
private:
    std::vector<int> parent;
};