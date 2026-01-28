#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {
public:
    int n;
    vector<int> parent, rankk;

    DisjointSet(int n) {
        this->n = n;
        parent.resize(n);
        rankk.assign(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]); 
    }

    void unionByRank(int x, int y) {
        int parentX = find(x);
        int parentY = find(y);

        if (parentX == parentY) return;

        if (rankk[parentX] == rankk[parentY]) {
            parent[parentY] = parentX;
            rankk[parentX]++;
        } else if (rankk[parentX] > rankk[parentY]) {
            parent[parentY] = parentX;
        } else {
            parent[parentX] = parentY;
        }
    }
};

int main() {
    DisjointSet dj(6);

    dj.unionByRank(0, 2);
    cout << dj.find(2) << endl;

    dj.unionByRank(1, 3);
    dj.unionByRank(2, 5);
    dj.unionByRank(0, 3);
    cout << dj.find(2) << endl;

    dj.unionByRank(0, 4);
    return 0;
}
