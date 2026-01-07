#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> DFS(int start, const vector<vector<int>>& g, int n,
    vector<bool>& visited, vector<int>& num, int& current_num) {
    bool is_top = false;
    stack<int> s;
    s.push(start);

    while (!s.empty()) {
        int v = s.top();
        if (!visited[v]) {
            visited[v] = true;
            num[v] = current_num++;
        }
        bool found = false;
        for (int i = 0; i < g[v].size(); i++) {
            int u = g[v][i];
            if (!visited[u]) {
                s.push(u);
                found = true;
                break;
            }
        }
        if (!found) {
            s.pop();
        }
    }
    return num;
}


int main() {
    setlocale(LC_ALL, "rus");
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n;
    in >> n;

    int** Ma = new int* [n + 1];
    for (int i = 0; i < n + 1; i++) {
        Ma[i] = new int[n + 1];
        for (int j = 0; j < n + 1; j++) {
            Ma[i][j] = 0;
        }
    }
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            int a;
            in >> a;
            Ma[i][j] = a;
        }
    }

    vector<vector<int>> g(n + 1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (Ma[i][j] == 1) {
                g[i].push_back(j);
            }
        }
        sort(g[i].begin(), g[i].end());
    }

    vector<int> nums(n + 1, 0);
    vector<bool> visited(n + 1, false);
    int current_num = 1;
    for (int start = 1; start <= n; start++) {
        if (!visited[start]) {
            DFS(start, g, n, visited, nums, current_num);
        }
    }

    for (int i = 1; i < nums.size(); i++) {
        out << nums[i] << " ";
    }

    for (int i = 0; i < n + 1; i++) {
        delete[] Ma[i];
    }
    delete[] Ma;

    in.close();
    out.close();

    return 0;
}