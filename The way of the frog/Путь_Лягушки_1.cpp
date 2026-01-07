#include <iostream>
#include <vector>
#include <climits> 
#include <algorithm> 
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    vector<long long> F(n + 1, LLONG_MIN);
    vector<int> path(n + 1, -1);

    F[1] = arr[1];
    F[2] = LLONG_MIN;

    for (int i = 3; i <= n; i++) {
        if (i - 2 >= 1 && F[i - 2] != LLONG_MIN) {
            long long val = F[i - 2] + arr[i];
            if (val > F[i]) {
                F[i] = val;
                path[i] = i - 2;
            }
        }

        if (i - 3 >= 1 && F[i - 3] != LLONG_MIN) {
            long long val = F[i - 3] + arr[i];
            if (val > F[i]) {
                F[i] = val;
                path[i] = i - 3;
            }
        }
    }

    if (F[n] == LLONG_MIN) {
        cout << -1 << endl;
        return 0;
    }

    vector<int> Path;
    for (int i = n; i != -1; i = path[i]) {
        Path.push_back(i);
    }
    reverse(Path.begin(), Path.end());

    cout << F[n] << endl;
    for (int i = 0; i < Path.size(); i++) {
        cout << Path[i]<<" ";
    }
    cout << endl;

    return 0;
}