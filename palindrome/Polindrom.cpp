#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ifstream in("input.txt");
    ofstream out("output.txt");
    string s;
    in >> s;
    int n = s.length();

    vector<vector<int>> F(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        F[i][i] = 1;
    }

    for (int i = 0; i < n - 1; i++) {
        int j = i + 1;
        if (s[i] == s[j]) {
            F[i][j] = 2;
        }
        else {
            F[i][j] = 1;
        }
    }

    for (int len = 3; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;

            if (s[i] == s[j]) {
                F[i][j] = F[i + 1][j - 1] + 2;
            }
            else {
                F[i][j] = max(F[i + 1][j], F[i][j - 1]);
            }
        }
    }

    string res;
    int i = 0, j = n - 1;

    while (i <= j) {
        if (s[i] == s[j]) {
            res += s[i];
            i++;
            j--;
        }
        else {
            if (F[i + 1][j] > F[i][j - 1]) {
                i++;
            }
            else {
                j--;
            }
        }
    }

    int L = F[0][n - 1];
    out << L << endl;

    string P = res;

    if (L % 2 == 0) {
        for (int k = res.length() - 1; k >= 0; k--) {
            P += res[k];
        }
    }
    else {
        for (int k = res.length() - 2; k >= 0; k--) {
            P += res[k];
        }
    }

    out << P << '\n';

    in.close();
    out.close();

    return 0;
}