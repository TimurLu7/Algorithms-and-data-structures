#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n, m;
    in >> n >> m;

    vector<vector<int>> arr(n+1);

    for (int i = 0; i < m; i++) {
        int u, v;
        in >> u >> v;

        arr[u].push_back(v);
        arr[v].push_back(u); 
    }

    for (int i = 1; i < n+1; i++) {
        out << arr[i].size();

        for (int a : arr[i]) {
            out << " "<< a;
        }
        out << endl;
    }

    in.close();
    out.close();

    return 0;
}