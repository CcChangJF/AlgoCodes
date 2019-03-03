#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<int, long long> pil;
typedef std::pair<long long, long long> pll;

using namespace std;
const int INF = 0x3f3f3f3f;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(400, 0);
        vector<int> prev(400, 0);
        for (int i = 0; i < days.size(); ++i) { prev[days[i]] = 1;}
        prev[0] = 0;
        int maxD = days[days.size() - 1];
        for (int i = 1; i <= maxD; ++i) {
            if (0 == prev[i]) { 
                dp[i] = dp[i - 1];
                continue; 
            }
            dp[i] = dp[i - 1] + costs[0];
            dp[i] = min(dp[i], (i >= 7 ? dp[i - 7] : 0 ) + costs[1]);
            dp[i] = min(dp[i], (i >= 30 ? dp[i - 30] : 0) + costs[2]);
            // cout << i << ": " <<  dp[i] << endl;
        }
        return dp[maxD];
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution s;
    vector<int> days = vector<int>({1,2,3,4,6,8,9,10,13,14,16,17,19,21,24,26,27,28,29});
    vector<int> costs = vector<int>({3,14,50});
    cout << s.mincostTickets(days, costs) << endl;


    return 0;
}