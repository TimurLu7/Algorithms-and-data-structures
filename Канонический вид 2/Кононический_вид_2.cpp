#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n;
    in >> n;
    vector<int> arr(n + 1, 0);

    int** Ma = new int* [n+1];
    for (int i = 0; i < n + 1; i++) {
        Ma[i] = new int[n + 1];
        for (int j = 0; j < n + 1; j++) {
            Ma[i][j] = 0;
        }
    }
    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < n+1; j++) {
            int a;
            in >> a;
            Ma[i][j] = a;
        }
    }

    for (int i = 0; i < n+1; i++) {
        for (int j = 0; j < n+1; j++) {
            if (Ma[i][j] == 1) {
                arr[j] = i;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        out << arr[i] << " ";
    }

    in.close();
    out.close();

    return 0;
}