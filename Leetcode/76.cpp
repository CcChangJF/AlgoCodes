
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;


class Solution {
public:
    string minWindow(string s, string t) {
        if (0 == t.length()) { return ""; }
        int minLen = INT_MAX;
        // vector<int> cnt = vector<int>(t.length(), 0);
        map<char, int> cnt = map<char, int>();
        for (int i = 0; i < t.length(); ++i) {
            ++cnt[t[i]];
        }
        int start = -1;
        int index1 = 0;
        map<char, int> curCnt = map<char,int>();
        int allNum = 0;
        int index0 = 0;
        while (index1 < s.size()) {
            if (cnt.count(s[index1]) > 0) {
                ++curCnt[s[index1]];
                if (curCnt[s[index1]] <= cnt[s[index1]]) {
                    ++allNum;
                }
            }
            // cout << allNum << " " << t.length() << endl;
            ++index1;
            while (allNum == t.length()) {
                if (cnt.count(s[index0]) > 0) {
                    // cout << "index: " << index0 << " " << index1 << endl;
                    if (curCnt[s[index0]] <= cnt[s[index0]]) {
                        if (minLen > index1 - index0) {
                            minLen = index1 - index0;
                            start = index0;
                        }
                        --allNum;
                    }
                    --curCnt[s[index0]];
                }
                ++index0;
            }

        }
        // cout << "min:" << minLen << endl;
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};


class Solution1 {
public:
    string minWindow(string s, string t) {
        if (0 == t.length()) { return ""; }
        int minLen = INT_MAX;
        // vector<int> cnt = vector<int>(t.length(), 0);
        map<char, int> cnt = map<char, int>();
        for (int i = 0; i < t.length(); ++i) {
            ++cnt[t[i]];
        }
        int start = -1;
        int index1 = 0;
        map<char, int> curCnt = map<char,int>();
        int allNum = 0;
        while(index1 < s.length()) {
            if (cnt.count(s[index1]) > 0) {
                ++curCnt[s[index1]];
                if (curCnt[s[index1]] <= cnt[s[index1]]) {
                    ++allNum;
                    if (allNum == t.length()) {
                        break;
                    }
                }
            }
            ++index1;
        }
        if (index1 == s.length()) { return ""; }
        // cout << "index1 : " << index1 << endl;
        int index0 = 0;
        while (index1 < s.size()) {
            while(index0 < index1) {
                if (cnt.count(s[index0]) > 0) {
                    if (curCnt[s[index0]] > cnt[s[index0]]) {
                        --curCnt[s[index0]];
                    }
                    else {
                        break;
                    }
                }
                ++index0;
            }
            // cout << "index0: " << index0 << endl;
            int curLen = index1 - index0 + 1;
            if (minLen > curLen) {
                minLen = curLen;
                start = index0;
            }
            // index1 point to the last element of substring.
            ++index1;
            char c = s[index0];
            --curCnt[s[index0]];
            ++index0;
            while(index1 < s.size()) {
                if (c == s[index1]) {
                    ++curCnt[c];
                    break;
                }
                else {
                    if (cnt.count(s[index1]) > 0) {
                        ++curCnt[s[index1]];
                    }
                }
                ++index1;
            }
        }
        // cout << "min:" << minLen << endl;
        return s.substr(start, minLen);
    }
};

int main() {
    Solution s;
    //"adobecodebancbbcaa"
    //"abc"
    //
    cout << s.minWindow("adobecodebancbbcaa", "abc") << endl;
    return 0;
}