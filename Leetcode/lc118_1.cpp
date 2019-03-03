#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<int, long long> pil;
typedef std::pair<long long, long long> pll;

using namespace std;
const int INF = 0x3f3f3f3f;

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> nums;
        vector<int> powerx(1,1);
        vector<int> powery(1,1);
        if (1 != x) {
            for (int i = 0; ; ++i) {
                int cur = powerx[powerx.size() - 1] * x;
                if (cur >= bound) { break; }
                powerx.push_back(cur);
            }
        }
        if (1 != y) {
            for (int i = 0; ; ++i) {
                int cur = powery[powery.size() - 1] * y;
                if (cur >= bound) { break; }
                powery.push_back(cur);
            }
        }
        for (int i = 0; i < powerx.size(); ++i) {
            for (int j = 0; j < powery.size(); ++j) {
                if (powerx[i] + powery[j] <= bound) {
                    nums.push_back(powerx[i] + powery[j]);
                }
            }
        }
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        return nums;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution s;
    vector<int> res;

    res = s.powerfulIntegers(1,3,10);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    cout << endl;

    res = s.powerfulIntegers(3,5,15);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}