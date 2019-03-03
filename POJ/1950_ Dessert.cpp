
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

class Solution{
    int eval(string &str) {
        // "1 . 2 - 3 + 4 + 5 . 6 . 7"
        int res = 0;
        int num = 0;
        int op = 1;
        for (int i = 0; i < str.length(); ++i) {
            if (' ' == str[i]) {
                continue;
            }
            else if ('0' <= str[i] && str[i] <= '9') {
                while (i < str.length() && '0' <= str[i] && str[i] <= '9') {
                    num = num * 10 + str[i] - '0';
                    ++i;
                }
            }
            else {
                if ('.' == str[i]) {
                    continue;
                }
                else {
                    res = (1 == op) ? res + num : res - num;
                    num = 0;
                    op = ('+' == str[i]) ? 1 : 2;
                }
            }
            // cout << "mid: " << num << " " << op << " " << res << endl; 
        }
        res = (1 == op) ? res + num : res - num;
        // cout << str << endl << "value: " << res << endl;
        return res;
    }

    void search(vector<string> &res, string cur, int val, int n) {
        if (val == n + 1) {
            if (0 == eval(cur)) {
                res.push_back(cur);
            }
        }
        else {
            string numStr = "";
            if (val < 10) {
                numStr = val + '0';
            }
            else {
                numStr.push_back((val / 10) + '0');
                numStr.push_back((val % 10) + '0'); 
            }
            search(res, cur + " + " + numStr, val + 1, n);
            search(res, cur + " - " + numStr, val + 1, n);
            search(res, cur + " . " + numStr, val + 1, n);
        }
        return;
    }
public:
    int count;
    vector<string> getDessert(int n) {
        // string str = "1 . 2 - 3 + 4 + 5 . 6 . 7";
        // cout << "eval: " << eval(str) << endl;


        count = 0;
        vector<string> res = vector<string>();
        // string cur = "1";
        search(res, "1", 2, n);
        count = res.size();
        if (count > 20) {
            res.erase(res.begin() + 20, res.end());
        }
        return res;
    }
};

int main() {
    Solution s;
    int n;
    while (cin >> n) {
        vector<string> res = s.getDessert(n);
        for (int i = 0; i < res.size(); ++i) {
            cout << res[i] << endl;
        }
        cout << s.count << endl;
    }

    return 0;
}