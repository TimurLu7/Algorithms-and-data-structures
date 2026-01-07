#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> m;
    int n = m;

    multiset<long long> sums;
    for (int i = 0; i < n * n; ++i) {
        long long x;
        cin >> x;
        sums.insert(x);
    }

    vector<long long> answer;

    long long first = *sums.begin() / 2;
    answer.push_back(first);

    sums.erase(sums.begin());

    while (answer.size() < n) {
        long long min_sum = *sums.begin();

        long long new_num = min_sum - answer[0];
        answer.push_back(new_num);

        for (long long a : answer) {
            long long sum_val = a + new_num;
            auto it = sums.find(sum_val);
            if (it != sums.end()) {
                sums.erase(it);
            }
        }
    }

    sort(answer.begin(), answer.end());

    for (long long num : answer) {
        cout << num << '\n';
    }

    return 0;
}