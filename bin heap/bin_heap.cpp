#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n;
    in >> n;

    vector<int> arr(n + 1); 

    for (int i = 1; i <= n; i++) {
        in >> arr[i];
    }

    bool isMinHeap = true;

    for (int i = 1; i <= n; i++) {
        int child1 = 2 * i;
        int child2 = 2 * i + 1;

        if (child1 <= n) {
            if (arr[i] > arr[child1]) {
                isMinHeap = false;
                break;
            }
        }

        if (child2 <= n) {
            if (arr[i] > arr[child2]) {
                isMinHeap = false;
                break;
            }
        }
    }

    if (isMinHeap) {
        out << "Yes";
    }
    else {
        out << "No";
    }

    return 0;
}