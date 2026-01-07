#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

double Calc_X(int i, const vector<double>& r, vector<double>& x) {
    if (i == 0) {
        x[0] = r[0];  
        return r[0];
    }

    if (x[i] != -1.0) {
        return x[i];
    }

    double center = r[i];
    for (int j = 0; j < i; j++) {
        double x_j = Calc_X(j, r, x);
        double d = 2.0 * sqrt(r[i] * r[j]);
        center = max(center, x_j + d);
    }

    x[i] = center;
    return center;
}

int main() {
    ifstream in("in.txt");
    ofstream out("out.txt");

    int n;
    in >> n;
    vector<double> r(n);
    for (int i = 0; i < n; i++) {
        in >> r[i];
    }

    vector<double> x(n, -1.0);

    for (int i = 0; i < n; i++) {
        Calc_X(i, r, x);
    }

    double length = 0;
    for (int i = 0; i < n; i++) {
        length = max(length, x[i] + r[i]);
    }

    out << fixed << setprecision(5) << length << endl;

    in.close();
    out.close();
    return 0;
}