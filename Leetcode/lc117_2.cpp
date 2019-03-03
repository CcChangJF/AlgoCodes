#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

class Solution {
    void dfs(vector<int> &res, int cur, int n, int digit, int k, int num) {
        if (cur == n) {
            res.push_back(num);
            return; 
        }
        else {
            if (digit + k < 10) {
                dfs(res, cur + 1, n, digit + k, k, num * 10 + digit + k);
            }
            if (k != 0 && digit - k >= 0) {
                dfs(res, cur + 1, n, digit - k, k, num * 10 + digit - k);
            }
            return;
        }
    }
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> res;
        if (1 == N) {
            for (int i = 0; i < 10; ++i) {
                res.push_back(i);
            }
        }
        else {
            for (int i = 1; i < 10; ++i) {
                dfs(res, 1, N, i, K, i);
            }
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    Solution s;
    vector<int> res;

    res = s.numsSameConsecDiff(2, 0);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    cout << endl;

    res = s.numsSameConsecDiff(3, 7);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    cout << endl;

    res = s.numsSameConsecDiff(1, 7);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}