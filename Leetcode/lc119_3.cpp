#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<int, long long> pil;
typedef std::pair<long long, long long> pll;

using namespace std;
const int INF = 0x3f3f3f3f;

class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int sz = A.size();
        vector<int> sum(sz + 1, 0);
        int ans = 0;
        for (int i = 0; i < sz; ++i) {
            sum[i + 1] = sum[i] + A[i];
        }
        for (int i = 1; i <= sz; ++i) {
            for (int j = 0; j < i; ++j) {
                if (0 == (sum[i] - sum[j]) % K) { 
                    // cout << i << "," << j << endl;
                    ++ans; 
                }
            }
        }
        return ans;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution s;
    vector<int> test;

    test = vector<int>({4,5,0,-2,-3,1});
    cout << s.subarraysDivByK(test, 5) << endl;


    return 0;
}