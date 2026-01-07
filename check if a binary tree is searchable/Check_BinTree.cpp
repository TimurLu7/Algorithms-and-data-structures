#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <climits>
#include <stack>

using namespace std;

struct Node {
	long long key;
	int left = -1;
	int right = -1;
};

int main() {
	ifstream in("bst.in");
	ofstream out("bst.out");
	
	int n;
	cin >> n;
	if (n == 0) {
		out << "YES" << endl;
	}

	vector<Node> tree(n);
	in >> tree[0].key;

	vector<int> parent(n, 0);
	vector<char> child(n, ' ');

	for (int i = 1; i < n; i++) {
		long long v;
		int p;
		char t;
		in >> v >> p >> t;
		
		tree[i].key = v;
		parent[i] = p;
		child[i] = t;
	}

	for (int i = 1; i < n; i++) {
		int p = parent[i];
		if (child[i] == 'L') {
			tree[p].left = i;
		}
		else {
			tree[p].right = i;
		}
	}

    bool Check = true;

    stack<pair<int, pair<long long, long long>>> st;
    st.push({ 0, {LLONG_MIN, LLONG_MAX} });

    while (!st.empty() && Check) {
        auto [index, range] = st.top();
        st.pop();

        long long min = range.first;
        long long max = range.second;
        long long val = tree[index].key;

        if (val < min || val > max) {
            Check = false;
            break;
        }

        if (tree[index].right != -1) {
            st.push({ tree[index].right, {val, max} });
        }

        if (tree[index].left != -1) {
            st.push({ tree[index].left, {min, val - 1} });
        }
    }

    if (Check) {
        out << "YES" << endl;
    }
    else {
        out << "NO" << endl;
    }

    in.close();
    out.close();

    return 0;
}