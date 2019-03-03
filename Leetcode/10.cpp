
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>

using namespace std;

class Solution {
    void dfsSet(string &p, set<int> &start, vector<int> &mark, set<int> &res) {
        for (set<int>::iterator iter = start.begin(); iter != start.end(); ++iter) {
            dfs(p, *iter, mark, res);
        }
        return;
    }
    
    void dfs(string &p, int v, vector<int> &mark, set<int> &res) {
        mark[v] = true;
        res.insert(v);
        if (v == p.length()) { 
            return;
        }
        if ('*' == p[v]) {
            res.insert(v + 1);
            if (!mark[v + 1]) {
                mark[v + 1] = true;
                dfs(p, v + 1, mark, res);
            }
            res.insert(v - 1);
            if (!mark[v - 1]) {
                mark[v - 1] = true;
                dfs(p, v - 1, mark, res);
            }
        }
        if (v + 1 < p.length() && '*' == p[v + 1]) {
            res.insert(v + 1);
            if (!mark[v + 1]) {
                mark[v + 1] = true;
                dfs(p, v + 1, mark, res);
            }
        }
        return;
    }

    void print(set<int> &s) {
        for (set<int>::iterator iter = s.begin(); iter != s.end(); ++iter) {
            cout << *iter << " ";
        }
        cout << endl;
    }
public:
    bool isMatch(string s, string p) {
        vector<int> mark = vector<int>(p.length() + 1, 0);
        set<int> reach = set<int>();
        set<int> start = set<int>({0});
        dfsSet(p, start, mark, reach);
        // cout << "begin: ";
        // print(reach);
        for (int i = 0; i < s.length(); ++i) {
            mark = vector<int>(p.length() + 1, 0);
            set<int> cur = set<int>();
            for (set<int>::iterator iter = reach.begin(); iter != reach.end(); ++iter) {
                if (*iter < p.length() && ('.' == p[*iter] || (s[i] == p[*iter]))) {
                    cur.insert(*iter + 1);
                }
            }
            // cout << "cur: ";
            // print(cur);
            reach = set<int>();
            dfsSet(p, cur, mark, reach);
            // print(reach);
            if (0 == reach.size()) {
                break;
            }
        }
        // cout << "end: " ;
        // print(reach);
        if (0 == s.length() && 0 == p.length()) { return true;}
        if (reach.size() > 0 && reach.end() != reach.find(p.length())) { 
            return true;
        }
        return false;
    }
};

int main() {
    Solution s;
    cout << s.isMatch("aa", "a*") << endl;
    cout << s.isMatch("ab", ".*c") << endl;
    cout << s.isMatch("aab", "c*a*b") << endl;
    cout << s.isMatch("mississippi", "mis*is*ip*.") << endl;

    return 0;
}