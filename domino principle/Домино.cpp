#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;

int BFS(int start, const vector<vector<int>>& g, int n) {
    vector<int> dist(n + 1, -1);
    dist[start] = 0;

    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int u : g[v]) {
            if (dist[u] == -1) {
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }

    bool all_fall = true;
    int current_time = 0;

    for (int i = 1; i <= n; i++) {
        if (dist[i] == -1) {
            all_fall = false;
            break;
        }
        current_time = (dist[i] > current_time) ? dist[i] : current_time;
    }

    if (all_fall) {
        return current_time;
    }
    else {
        return -1;
    }
}

int main() {
    ifstream in("in.txt");
    ofstream out("out.txt");

    int n;
    in >> n;

    vector<vector<int>> g(n + 1);

    for (int i = 1; i <= n; i++) {
        int m;
        in >> m;
        g[i].resize(m);
        for (int j = 0; j < m; j++) {
            in >> g[i][j];
        }
    }

    int result_time = -1;
    int Start = -1;

    for (int start = 1; start <= n; start++) {
        int current_time = BFS(start, g, n);

        if (current_time != -1) {
            if (current_time > result_time || (current_time == result_time && start > Start)) {
                result_time = current_time;
                Start = start;
            }
        }
    }

    if (Start == -1) {
        out << "impossible" << endl;
    }
    else {
        out << result_time << endl;
        out << Start << endl;
    }

    in.close();
    out.close();
    return 0;
}