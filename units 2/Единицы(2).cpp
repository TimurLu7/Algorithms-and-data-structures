#include <iostream>
using namespace std;

const int m = 1000000007;

long long bin_pow(long long a, long long deg) {
    if (deg == 0) return 1;
    if (deg == 1) return a % m;

    long long h = bin_pow(a, deg / 2);
    h = h * h % m;

    if (deg % 2 == 1) {
        return h * a % m;  
    }
    return h;              
}

long long fact(int N) {
    if (N == 0 || N == 1)
        return 1;
    return N * fact(N - 1);
}

long long inv_fact(int N) {
    long long f = fact(N);
    return bin_pow(f, m - 2);
}

long long C(int n, int k) {

    long long a = fact(n);
    long long b = (fact(k) * fact(n - k)) % m;
    long long inv_b = bin_pow(b, m - 2);

    return (a * inv_b) % m;
}

int main() {
    int N, K;
    cin >> N >> K;

    cout << C(N, K) << endl;

    return 0;
}