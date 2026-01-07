#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n;
    in >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        in >> arr[i];
    }

    vector<int> f; 

    for (int i = 0; i < n; i++) {
        auto it = lower_bound(f.begin(), f.end(), arr[i]);

        if (it == f.end()) {
            f.push_back(arr[i]);
        }
        else {
            *it = arr[i];
        }
    }

    out << f.size() << endl;
    in.close();
    out.close();
    return 0;
}