#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int m, c, n;
    in >> m >> c >> n;

    vector<long long> arr(m, -1);

    for (int k = 0; k < n; k++) {
        long long x;
        in >> x;

        bool is_dup = false;
        for (int i = 0; i < m; i++) {
            if (arr[i] == x) {
                is_dup = true;
                break;
            }
        }

        if (is_dup) {
            continue;
        }

        for (int i = 0; i < m; i++) {
            int ind = ((x % m) + c * i) % m;

            if (arr[ind] == -1) {
                arr[ind] = x; 
                break;  
            }
        }
    }

    for (int i = 0; i < m; i++) {
        out << arr[i] << " ";
    }
    out << endl;

    return 0;
}