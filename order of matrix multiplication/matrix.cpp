#include <iostream>
#include <fstream>
#include <climits>

using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    if (!in.is_open() || !out.is_open()) {
        return 1;
    }

    int s;
    in >> s;

    int pr[101] = { 0 };

    int rows, cols;
    for (int i = 0; i < s; i++) {
        int rows, cols;
        in >> rows >> cols;
        pr[i] = rows;
        pr[i + 1] = cols;
    }

    int F[101][101];

    for (int i = 0; i < s; i++) {
        F[i][i] = 0;
    }

    for (int i = 0; i < s - 1; i++) {
        F[i][i + 1] = pr[i] * pr[i + 1] * pr[i + 2];
    }

    for (int len = 3; len <= s; len++) {
        for (int i = 0; i <= s - len; i++) {
            int j = i + len - 1;
            F[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int res = F[i][k] + F[k + 1][j] + pr[i] * pr[k + 1] * pr[j + 1];

                if (res < F[i][j]) {
                    F[i][j] = res;
                }
            }
        }
    }

    out << F[0][s - 1] << endl;

    in.close();
    out.close();
    return 0;
}