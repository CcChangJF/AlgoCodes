#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<int, long long> pil;
typedef std::pair<long long, long long> pll;

using namespace std;
const int INF = 0x3f3f3f3f;

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<vector<int> > judges(N + 1, vector<int>());
        vector<int> cnt(N + 1, 0);
        for (int i = 0; i < trust.size(); ++i) {
            judges[trust[i][1]].push_back(trust[i][0]);
            ++cnt[trust[i][0]];
        }
        for (int i = 1; i <= N; ++i) {
            judges[i].erase(unique(judges[i].begin(), judges[i].end()), judges[i].end());
            if (N - 1 == judges[i].size() && 0 == cnt[i]) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);



    return 0;
}