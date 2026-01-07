#include <iostream>
#include <vector>
#include <string>


using namespace std;

class fenwick {
private:
    vector<long long> t;

public:
    fenwick(int n) {
        t.resize(n + 1, 0);
    }

    long long Sum(int position) {
        long long sum = 0;
        for (int i = position; i > 0; i -= i & (-i)) {
            sum += t[i];
        }
        return sum;
    }

    void Update(int position, long long x) {
        for (int i = position + 1; i < t.size(); i += i & (-i)) {
            t[i] += x;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    fenwick fenwick(n);
    vector<long long> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        fenwick.Update(i, arr[i]);
    }

    int q;
    cin >> q;
    vector<long long> result;

    for (int i = 0; i < q; i++) {
        string command;
        cin >> command;

        if (command == "Add") {
            int position;
            long long x;
            cin >> position >> x;

            fenwick.Update(position, x);
            arr[position] += x;
        }
        else if (command == "FindSum") {
            int l, r;
            cin >> l >> r;
            result.push_back(fenwick.Sum(r)- fenwick.Sum(l));
        }
    }
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    return 0;
}