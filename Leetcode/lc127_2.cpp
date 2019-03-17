#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<int, long long> pil;
typedef std::pair<long long, long long> pll;

using namespace std;
const int INF = 0x3f3f3f3f;

class Solution {
    int last(int N) {
        if (N <= 1) { return N; }
        else if (2 == N) { return N * ( N - 1); }
        else if (3 == N) { return N * ( N - 1) / (N - 2);}
        else {
            return 0;
        }
    }
public:
    int clumsy(int N) {
        int p = N % 4;
        int ans = last(p);
        if (N < 4) { return ans; }
        else { ans = -ans; }
        while(p + 4 < N) {
            int cur = p + 4;
            ans = ans - cur * (cur - 1) / (cur - 2) + (cur - 3);
            p += 4;
        }
        return N * (N - 1) / (N - 2) + N - 3 + ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution s;
    for (int i = 1; i < 11; ++i) {
        cout << i << ": " << s.clumsy(i) << endl;
    }
    return 0;
}