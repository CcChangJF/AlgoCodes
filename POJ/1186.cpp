#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>

using namespace std;


const int size = 4000000;

struct Hash{
    int val;
    int count;
};

Hash hashTable[size];
bool used[size];
vector<int> k;
vector<int> p;



    int searchPos(int val) {
        int pos = (val % size + size) % size;
        while (1 == used[pos] && val != hashTable[pos].val) {
            //cout << "pos: " << pos << endl;
            ++pos;
            if (pos >= size) {
                pos -= size;
            }
        }
        return pos;
    }

    void insert(int val) {
        int pos = searchPos(val);
        hashTable[pos].val = val;
        ++hashTable[pos].count;
        used[pos] = 1;
    }

    int power(int x, int t) {
        int res = 1;
        int cur = x;
        while (0 != t) {
            if (1 == t % 2) {
                res = res * cur;
            }
            cur = cur * cur;
            t /= 2;
        }
        return res;
    }

    void dfsLeft(int n, int m, int cur, int sum) {
        if (cur == n) {
            //cout << "hello world";
            //cout << "sum: "<< sum << endl;
            insert(sum);
            //cin >> sum;
            //cout << sum << endl;
        }
        else {
            for (int i = 1; i <= m; ++i) {
                int curValue = k[cur] * power(i, p[cur]);
                sum += curValue;
                //cout << "sum: " << sum << " " << cur << " " << n<< endl;
                dfsLeft(n, m, cur + 1, sum);
                sum -= curValue;
            }
        }
    }

    void dfsRight(int n, int m, int cur, int sum, int &count) {
        if (cur == n) {
            int pos = searchPos(-1 * sum);
            if (hashTable[pos].val == -1 * sum) {
                count += hashTable[pos].count;
            }
        }
        else {
            for (int i = 1; i <= m; ++i) {
                int curValue = k[cur] * power(i, p[cur]);
                sum += curValue;
                dfsRight(n, m, cur + 1, sum, count);
                sum -= curValue;
            }
        }
    }

    void numberOfSol(int n, int m, int &count) {
        //cout << "here" << endl;
        count = 0;
        dfsLeft(n / 2, m, 0, 0);
        dfsRight(n, m, n / 2, 0, count);
        return;
    }


int main() {
    int n;
    while (cin >> n) {
        int m;
        cin >> m;
        k = vector<int>(n, 0);
        p = vector<int>(n, 0);
        for (int i = 0; i < n; ++i) {
            cin >> k[i] >> p[i];
        }
        int count = 0;
        numberOfSol(n, m, count);
        cout << count << endl;
    }
    return 0;
}