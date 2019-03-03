
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
    vector<int> fac;
private:
    int getCurNum(int k) {
        int cur = 0;
        for (int i = 1; i < fac.size(); ++i){
            if ( fac[i] >= k) {
                cur = i;
                break;
            }
        }
        return cur;
    }
    int getMin(vector<int> &vec, int index) {
        int ret = -1;
        int cnt = 0;
        for (int i = 0; i < vec.size(); ++i) {
            if (0 != vec[i]) {
                ++cnt;
                if (index == cnt) {
                    ret = i;
                    vec[i] = 0;
                    break;
                }
            }
        }
        return ret;
    }
public:
    Solution() {
        fac = vector<int>(10);
        fac[0] = 1;
        for (int i = 1; i < 10; ++i) {
            fac[i] = fac[i - 1] * i;
        }
    }
    string getPermutation(int n, int k) {
        if (k <= 0 || n <= 0) { return "0";}
        vector<int> res = vector<int>(n,0);
        vector<int> ori = vector<int>(n + 1,1);
        ori[0] = 0;
        int startNum = 0;
        int cnt = 0;
        while(0 != k) {
            int num = getCurNum(k);
            startNum = n - num;
            for (int i = cnt; i < startNum; ++i) {
                res[cnt++] = getMin(ori, 1);
            }
            int cur = (k - 1) / fac[num - 1];
            res[cnt++] = getMin(ori,cur + 1);
            k -= max(cur, 1) * fac[num - 1];
        }
        string str = "";
        for (int i = 0; i < res.size(); ++i) {
            str.push_back(res[i] + '0');
        }
        return str;
    }
};

int main() {
    // n = 0 || k == 0
    // k == 1 || k == n!
    // n! > INT_MAX
    Solution s;
    // cout << s.getPermutation(4,4) << endl;

    for (int i = 1; i < 25; ++i) {
        cout << s.getPermutation(4, i) << endl;
    }

    return 0;
}