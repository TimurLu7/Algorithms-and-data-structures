#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> A(n), B(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }

    vector<vector<int>> f(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (A[i - 1] == B[j - 1]) {  
                f[i][j] = f[i - 1][j - 1] + 1;
            }
            else {
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            }
        }
    }

    int k = f[n][n];

    vector<int> a, b;
    int i = n, j = n;

    while (i > 0 && j > 0) {
        if (A[i - 1] == B[j - 1]) { 
            a.push_back(i - 1);
            b.push_back(j - 1);
            i--;
            j--;
        }
        else if (f[i - 1][j] > f[i][j - 1]) {
            i--;
        }
        else {
            j--;
        }
    }

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    cout << k << endl;

    for (int i : a) {
        cout << i << " ";
    }
    cout << endl;

    for (int i : b) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}