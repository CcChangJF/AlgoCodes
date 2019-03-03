
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

class Solution{

    void search(int sum, int cur, int pre, int n, vector<char> &opers) {
        if (cur == n + 1) {
            if (0 == sum) {
                ++count;
                if (count <= 20) {
                    vector<char> ans = vector<char>();
                    ans.push_back('1');
                    for (int i = 2; i <= n; ++i) {
                        ans.push_back(' ');
                        ans.push_back(opers[i - 2]);
                        ans.push_back(' ');
                        if (i < 10) {
                            ans.push_back(i + '0');
                        }
                        else {
                            ans.push_back(i / 10 + '0');
                            ans.push_back(i % 10 + '0');
                        }
                    }
                    res.push_back(string(ans.begin(), ans.end()));
                }
            }
        }
        else {
            opers.push_back('+');
            search(sum + cur, cur + 1, cur, n, opers);
            opers.pop_back();

            opers.push_back('-');
            search(sum - cur, cur + 1, -cur, n, opers);
            opers.pop_back();

            opers.push_back('.');
            int newVal = 0;
            if (cur < 10) {
                newVal = pre * 10;
            }
            else {
                newVal = pre * 100;
            }
            newVal = (pre > 0) ? newVal + cur : newVal - cur;
            search(sum - pre + newVal, cur + 1, newVal, n, opers);
            opers.pop_back();
        }
        return;
    }
public:
    int count;
    vector<string> res;
    void getDessert(int n) {
        count = 0;
        res = vector<string>();
        // string cur = "1";
        vector<char> ops = vector<char>();
        search(1, 2, 1, n, ops);
    }
};

int main() {
    Solution s;
    int n;
    while (cin >> n) {
        s.getDessert(n);
        for (int i = 0; i < s.res.size(); ++i) {
            cout << s.res[i] << endl;
        }
        cout << s.count << endl;
    }

    return 0;
}