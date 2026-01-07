#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct DSU {
    vector<int> parent;
    vector<int> size;
    int components;

    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        components = n;

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y) {
            return;
        }
        if (size[x] < size[y]) {
            swap(x, y);
        }
        parent[y] = x;
        size[x] += size[y];
        components--;
    }
};

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    in >> n >> m >> q;

    vector<pair<int, int>> edges(m + 1);
    for (int i = 1; i <= m; i++) {
        in >> edges[i].first >> edges[i].second;
    }

    vector<int> queries(q);
    vector<bool> destroyed(m + 1, false);

    for (int i = 0; i < q; i++) {
        in >> queries[i];
        destroyed[queries[i]] = true;
    }

    DSU dsu(n);

    for (int i = 1; i <= m; i++) {
        if (!destroyed[i]) {
            dsu.unite(edges[i].first, edges[i].second);
        }
    }

    vector<char> results(q);
    for (int i = q - 1; i >= 0; i--) {
        if (dsu.components == 1) {
            results[i] = '1';
        }
        else {
            results[i] = '0';
        }

        int edgeId = queries[i];
        dsu.unite(edges[edgeId].first, edges[edgeId].second);
    }

    for (char c : results) {
        out << c;
    }
    out << '\n';

    return 0;
}