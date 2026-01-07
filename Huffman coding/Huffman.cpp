#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ifstream fin("huffman.in");
    ofstream fout("huffman.out");

    int n;
    fin >> n;  

    queue<long long> q1; 
    queue<long long> q2; 

    for (int i = 0; i < n; i++) {
        long long p;
        fin >> p;
        q1.push(p);
    }

    long long length = 0;  

    for (int i = 0; i < n - 1; i++) {
        long long min1, min2;

        if (q2.empty() || (!q1.empty() && q1.front() <= q2.front())) {
            min1 = q1.front();
            q1.pop();
        }
        else {
            min1 = q2.front();
            q2.pop();
        }

        if (q2.empty() || (!q1.empty() && q1.front() <= q2.front())) {
            min2 = q1.front();
            q1.pop();
        }
        else {
            min2 = q2.front();
            q2.pop();
        }

        long long sum = min1 + min2;

        length += sum;

        q2.push(sum);
    }

    fout << length << endl;

    fin.close();
    fout.close();

    return 0;
}