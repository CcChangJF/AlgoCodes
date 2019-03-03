#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

class Solution {
    void dfs(int x, int sum, int target, int curOps, int lastNum) {
        getchar();
        cout << sum << " " << curOps << " " << lastNum << endl;
        if (curOps + 2 * abs(target - sum) - 1 >= maxT) { return;}
        if (sum == target) {
            maxT = min(maxT, curOps);
            return;
        }
        for (int i = 0; i < 4; ++i) {
            int temp = 0;
            switch(i) {
                case 0:
                    dfs(x, sum + x, target, curOps + 1, x);
                    break;
                case 1:
                    dfs(x, sum - x, target, curOps + 1, x * (-1));
                    break;
                case 2:
                    temp = sum - lastNum;
                    lastNum *= x;
                    dfs(x, temp + lastNum, target, curOps + 1, lastNum);
                    break;
                case 3:
                    temp = sum - lastNum;
                    lastNum /= x;
                    dfs(x, temp + lastNum, target, curOps + 1, lastNum);
                    break;
            }
        }
    }
public:
    int maxT;
    int leastOpsExpressTarget(int x, int target) {
        maxT = target + target - 1;
        dfs(x, x, target, 1, x);
        dfs(x, x * x, target, 1, 0);
        dfs(x, 1, target, 1, 0);
        return maxT;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution s;
    cout << s.leastOpsExpressTarget(3,19) << endl;
    // cout << s.leastOpsExpressTarget(5,501) << endl;
    // cout << s.leastOpsExpressTarget(100,10000000) << endl;


    return 0;
}