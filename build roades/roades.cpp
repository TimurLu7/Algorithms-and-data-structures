#include <iostream>
#include <fstream>
#include <vector>

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
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n, q;
    fin >> n >> q;

    DSU dsu(n);

    for (int i = 0; i < q; i++) {
        int u, v;
        fin >> u >> v;
        dsu.unite(u, v);
        fout << dsu.components << "\n";
    }

    fin.close();
    fout.close();

    return 0;
}