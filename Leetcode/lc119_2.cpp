#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<int, long long> pil;
typedef std::pair<long long, long long> pll;

using namespace std;
const int INF = 0x3f3f3f3f;

class Solution {
    int bs(int target, vector<int> &A, int s, int e) {
        while(s < e) {
            int m = s + e >> 1;
            if (A[m] < target) {
                s = m + 1;
            }
            else { e = m; }
        }
        return s;
    }
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(), A.end());
        int sz = A.size();
        int ans = 0;
        for (int i = sz - 3; i >= 0; --i) {
            for (int j = sz - 2; j > i; --j) {
                if (2 * (A[i] + A[j]) <= ans) { continue; }
                int t = bs(A[i] + A[j], A, j + 1, sz);
                if (j + 1 < t && t <= sz) {
                    ans = max(ans, A[i] + A[j] + A[t - 1]);
                }
            }
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);



    return 0;
}