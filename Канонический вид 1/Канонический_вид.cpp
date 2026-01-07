#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");  

    int n;
    in >> n;

    vector<int> arr(n + 1, 0);

    for (int i = 1; i <= n-1; i++) {
        int u, v;
        in >> u >> v;
        arr[v] = u;  
    }

    for (int i = 1; i <= n; i++) {
        out << arr[i] << " ";
    }

    in.close();
    out.close();
    return 0;
}