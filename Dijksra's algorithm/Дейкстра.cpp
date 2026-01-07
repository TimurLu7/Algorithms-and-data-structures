#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n, m;
    in >> n >> m;

    vector<vector<pair<int, long long>>> graph(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        in >> u >> v >> w;
        graph[u].push_back({ v, w });
        graph[v].push_back({ u, w }); 
    }

    vector<long long> dist(n + 1, LLONG_MAX);
    dist[1] = 0;

    priority_queue<pair<long long, int>,
        vector<pair<long long, int>>,
        greater<pair<long long, int>>> pq;

    pq.push({ 0, 1 }); 

    while (!pq.empty()) {
        long long current_dist = pq.top().first;
        int current_vertex = pq.top().second;
        pq.pop();

        if (current_dist > dist[current_vertex]) {
            continue;
        }

        for (auto& neighbor : graph[current_vertex]) {
            int next_vertex = neighbor.first;
            long long weight = neighbor.second;

            long long new_dist = current_dist + weight;

            if (new_dist < dist[next_vertex]) {
                dist[next_vertex] = new_dist;
                pq.push({ new_dist, next_vertex });
            }
        }
    }

    out << dist[n] << endl;

    in.close();
    out.close();

    return 0;
}