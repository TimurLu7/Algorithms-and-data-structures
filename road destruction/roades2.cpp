#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

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
        parent[y] = x;
        size[x] += size[y];
        components--;
    }
};

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n, m, q;
    fin >> n >> m >> q;

    vector<pair<int, int>> roads(m + 1);
    for (int i = 1; i <= m; i++) {
        fin >> roads[i].first >> roads[i].second;
    }

    vector<bool> destroyed(m + 1, false);
    vector<int> earthquakes(q);
    for (int i = 0; i < q; i++) {
        fin >> earthquakes[i];
        destroyed[earthquakes[i]] = true;
    }

    DSU dsu(n);
    for (int i = 1; i <= m; i++) {
        if (!destroyed[i]) {
            dsu.unite(roads[i].first, roads[i].second);
        }
    }

    stack<bool> results;
    for (int i = q - 1; i >= 0; i--) {
        results.push(dsu.components == 1);

        int road_index = earthquakes[i];
        dsu.unite(roads[road_index].first, roads[road_index].second);
    }

    while (!results.empty()) {
        fout << results.top();
        results.pop();
    }

    fin.close();
    fout.close();

    return 0;
}