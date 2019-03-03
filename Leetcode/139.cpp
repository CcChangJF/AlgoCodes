
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cstdlib>
#include <ctime>
#include <string.h>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (0 == wordDict.size()) { return false;}
        vector<bool> dp = vector<bool>(s.length() + 1, false);
        set<string> words = set<string>();
        int minLen = INT_MAX;
        int maxLen = 0;
        for (int i = 0; i < wordDict.size(); ++i) {
            words.insert(wordDict[i]);
            int len = wordDict[i].length();
            if (minLen > len) {
                minLen = len;
            }
            if (maxLen < len) {
                maxLen = len;
            }
        }
        int index = 0;
        dp[0] = true;
        while (index <= s.length() - minLen) {
            if (!dp[index]) {
                ++index;
                continue;
            }
            for (int i = minLen; i <= maxLen & index + i <= s.length(); ++i) {
                string sub = s.substr(index, i);
                // cout << sub << endl;
                if (!dp[index + i] && 0 != words.count(sub)) {
                    // cout << index + i << endl;
                    dp[index + i] = true;
                }
            }
            ++index;
        }
        return dp[s.length()];
    }
};

class Solution1 {
public:
    int maxLen;
    int minLen;
    bool dfs(string &s, set<string> &words, int start) {
        if (s.length() == start) {
            return true;
        }
        else {
            for (int i = minLen; i <= maxLen; ++i) {
                string sub = s.substr(start, i);
                // cout << sub << endl;
                if (0 != words.count(sub) && dfs(s, words, start + sub.length())) {
                    return true;
                }
            }
            return false;
        }
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> words = set<string>();
        minLen = INT_MAX;
        maxLen = 0;
        for (int i = 0; i < wordDict.size(); ++i) {
            words.insert(wordDict[i]);
            int len = wordDict[i].length();
            if (minLen > len) {
                minLen = len;
            }
            if (maxLen < len) {
                maxLen = len;
            }
        }
        return dfs(s, words, 0);
    }
};

int main() {
    Solution s;
    vector<string> test;

    test = vector<string>({"apple", "pen"});
    cout << s.wordBreak("applepenapple", test) << endl;


    test = vector<string>({"cats", "dog", "sand", "and", "cat"});
    cout << s.wordBreak("catsandog", test) << endl;
    // test = vector<string>({});
    // cout << s.wordBreak(, test) << endl;
    return 0;
}