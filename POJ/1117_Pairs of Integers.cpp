#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

class Solution {
    bool strike(int a, int b) {
        int flag = false;
        while(0 != a || 0 != b) {
            if (a % 10 != b % 10) {
                if (flag) { return false;}
                flag = true;
                a /= 10;
            }
            else {
                a /= 10;
                b /= 10;
            }
        }
        return true;
    }

public:
    vector<string> sumToTarget(int target) {
        vector<string> res = vector<string>();
        string strTar = "";
        int t = target;
        int upper = 0;
        while (0 != t) {
            strTar.insert(strTar.begin(), t % 10 + '0');
            t /= 10;
            upper = upper * 10 + 9;
        }
        for (int i = upper / 10; i >= 0; --i) {
            if (strike(target - i, i)) {
                string sa = "";
                string sb = "";
                int a = target - i;
                int b = i;
                while (0 != a || 0 != b) {
                    if (a % 10 == b % 10) {
                        sb.insert(sb.begin(), b % 10 + '0');
                        b /= 10;
                    }
                    sa.insert(sa.begin(), a % 10 + '0');
                    a /= 10;
                }
                string cur = sa + " + " + sb + " = " + strTar;
                res.push_back(cur);
            }
        }
        return res;
    }
};


int main() {
    int n;
    cin >> n;
    Solution s;
    vector<string> res = s.sumToTarget(n);
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << endl;
    }
    return 0;
}