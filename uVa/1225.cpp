
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>


using namespace std;

class Solution{
    vector<int> cnt;
    vector<int> powers;
public:
    Solution() {
        powers = vector<int>({1, 10, 100, 1000, 10000, 100000});
        cnt = vector<int> (6, 0);
        for (int i = 1; i < 6; ++i) {
            cnt[i] = 10 * cnt[i - 1] + powers[i - 1];
            // cout << cnt[i][0] << " \t" << cnt[i][1] << endl;
        }
    }

    vector<int> countNum(int n) {
        vector<int> res = vector<int>(10, 0);
        if (n <= 0) { return res;}
        int len = 0;
        int t = n;
        while (0 != t) {
            t /= 10;
            ++len;
        }
        int remain = n;
        int cur = 0;
        int curLen = len;
        while (0 != len) {
            int curDig = n / powers[--len];
            for (int i = 0; i < 10; ++i) {
                res[i] += cnt[len] * curDig;
            }   
            for (int i = 0; i < curDig; ++i) {
                res[i] += powers[len];
            } 
            n -= curDig * powers[len];
            res[curDig] += (n + 1);
        }

        for (int i = 0; i < curLen; ++i) {
            res[0] -= powers[i];
        }

        return res;
    }
};

void print(vector<int> &nums) {
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
}
int main() {
    Solution s;
    vector<int> ans = vector<int>(10, 0);
    for (int i = 1; i <= 1000; ++i) {
        int k = i;
        while (0 != k) {
            ++ans[k % 10];
            k /= 10;
        }
        if (i >= 100) {
            vector<int> test = s.countNum(i);
            for (int k = 0; k < 10; ++k) {
                if (test[k] != ans[k]) {
                    cout << i << ": " << endl;
                    cout << "ans: ";
                    print(ans);
                    cout << "cal: ";
                    print(test);
                }
            }
        }
    }
    // int t;
    // cin >> t;
    // while(t--) {
    //     int n;
    //     cin >> n;
    //     vector<int> ans = s.countNum(n);
    //     cout << ans[0];
    //     for (int i = 1; i < ans.size(); ++i) {
    //         cout << " " << ans[i];
    //     }
    //     cout << endl;
    // }
    return 0;
}