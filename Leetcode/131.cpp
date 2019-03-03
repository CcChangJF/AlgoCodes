


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

class Solution {
    vector<vector<bool> > palindrome(string s) {
        vector<vector<bool> > res(s.length(), vector<bool>(s.length(), false));
        if (0 == s.length()) { return res;}
        for (int i = s.length() - 1; i >= 0; --i) {
            s.insert(s.begin() + i, '#');
        }
        s.push_back('#');
        int maxReach = 0;
        int maxCen = 0;
        vector<int> lst = vector<int>(s.length(), 1);
        for (int i = 1; i < s.length(); ++i) {
            lst[i] = (i >= maxReach) ? 1 : min(lst[2 * maxCen - i], maxReach - i);
            while (i >= lst[i] && i + lst[i] < s.length() && s[i + lst[i]] == s[i - lst[i]]) {
                ++lst[i];
            }
            if (maxReach < i + lst[i]) {
                maxReach = i + lst[i];
                maxCen = i;
            }
        }
        for (int i = 0; i < s.length() - 1; ++i) {
            for (int j = 1; j < lst[i]; j = j + 2) {
                //if ('#' != s[i - j + 1] && '#' != s[i + j - 1]) {
                    res[(i - j + 1) / 2][(i + j - 1) / 2] = true;
                //}
            }
        }
        return res;
    }
                                  
    void dfs(vector<vector<string>> &res, vector<string> &cur, 
            vector<vector<bool> > &reach, string &s, int start) {
        if (start == s.length()) {
            res.push_back(cur);
            return;
        }
        else {
            for (int i = start; i < s.length(); ++i) {
                if (reach[start][i]) {
                    cur.push_back(s.substr(start, i - start + 1));
                    dfs(res, cur, reach, s, i + 1);
                    cur.pop_back();
                }
            }
            return;
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > res;
        if (0 == s.length()) { return res;}
        vector<vector<bool> > reach = palindrome(s);
        // for (int i = 0; i < reach.size(); ++i) {
        //     for (int j = 0; j < reach[i].size(); ++j) {
        //         cout << reach[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        vector<string> cur = vector<string>();
        dfs(res, cur, reach, s, 0);
        return res;
    }
};


int main() {
    Solution s;
    vector<vector<string>> res = s.partition("aba");
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}