#include <iostream>
#include <fstream>

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n, m;
    in >> n >> m; 

    int** Ma = new int* [n];
    for (int i = 0; i < n; i++) {
        Ma[i] = new int[n];
        for (int j = 0; j < n; j++) {
            Ma[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        in >> u >> v;
        u--;
        v--;
        Ma[u][v] = 1;
        Ma[v][u] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            out << Ma[i][j]<<" ";
        }
        out << endl; 
    }

    in.close();
    out.close();

    return 0;
}