#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
    int m = 1000000007;
	int N, K;
	cin >> N >> K;
    int** F = new int* [1001];
    for (int i = 0; i < 1001; i++) {
        F[i] = new int[1001];
    }

    for (int i = 0; i <= N; i++) {
        F[i][0] = 1;  
        F[i][i] = 1; 

        for (int j = 1; j < i; j++) {
            F[i][j] = (F[i - 1][j - 1] + F[i - 1][j]) % m;
        }
    }
    cout << F[N][K] << endl;

    for (int i = 0; i < 1001; i++) {
        delete[] F[i];
    }
    delete[] F;

    return 0;
}

