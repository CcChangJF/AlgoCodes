
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>


using namespace std;

class Solution {
    void kmp(vector<string> &match, string &s, string word) {
        int len = 0;
        int index = 1;
        vector<int> pat = vector<int>(word.length(), 0);
        while (index < word.length()) {
            if (word[index] == word[len]) {
                ++len;
                pat[index] = len;
                ++index;
            }
            else {
                if (0 == len) {
                    pat[index] = 0;
                    ++index;
                }
                else {
                    len = pat[len - 1];
                }
            }
        }

        index = 0;
        int indexPat = 0;
        while (index < s.length()) {
            if (s[index] == word[indexPat]) {
                ++index;
                ++indexPat;
            }
            else {
                if (0 == indexPat) {
                    ++index;
                }
                else {
                    indexPat = pat[indexPat - 1];
                }
            }
            if (indexPat == word.length()) {
                match[index - indexPat] = word;
            }
        }
        return;
    }

    vector<string> subString(string &s, map<string, int> &words) {
        vector<string> res = vector<string>(s.length(), "");
        for (map<string, int>::iterator iter = words.begin(); iter != words.end(); ++iter) {
            kmp(res, s, iter -> first);
        }
        return res;
    }

public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans = vector<int>();
        if ("" == s || 0 == words.size()) {
            return ans;
        }
        map<string, int> cnt = map<string, int>();
        // int minLength = INT_MAX;
        // int maxLength = 0;
        int totalLength = 0;
        for (int i = 0; i < words.size(); ++i) {
            ++cnt[words[i]];
            // minLength = min(minLength, (int)words[i].length());
            // maxLength = max(maxLength, (int)words[i].length());
            totalLength += words[i].length();
        }
        vector<string> match = subString(s, cnt);
        // for (int i = 0; i < match.size(); ++i) {
        //     if ("" != match[i]) {
        //         cout << i << ": " << match[i] << endl;
        //     }
        // }
        map<string, int> curCnt = map<string, int>();
        int start = 0;
        int end = 0;
        int counter = 0;
        int curLength = 0;
        while(end < s.length()) {
            if ("" != match[end] ) {
                if (curCnt[match[end]] < cnt[match[end]]) {
                    ++curCnt[match[end]];
                    ++counter;
                    // cout << "end: " << end << ", " << match[end] << endl;
                    end = end + match[end].length();
                    curLength += match[end].length();
                }
                else {
                    start = end - curLength;
                    while (match[start] != match[end]) {
                        --curCnt[match[start]];
                        --counter;
                        start += match[start].length();
                        curLength -= match[start].length();
                    }
                    if (start < end) {
                        curLength -= match[start].length();
                        --curCnt[match[end]];
                        --counter;
                    }
                }
            }
            else {
                curCnt.clear();
                curLength = 0;
                counter = 0;
                ++end;
            }

            if(counter == words.size()) {
                start = end - totalLength;
                ans.push_back(start);
                if ("" == match[start + 1] || 1 == match[start].length()) {
                    --curCnt[match[start]];
                    --counter;
                    curLength -= match[start].length();
                }
                else {
                    end = start + 1;
                    curCnt.clear();
                    counter = 0;
                    curLength = 0;
                }
                
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<string> words;
    vector<int> res;

    words = vector<string>({"foo", "bar"});
    res = s.findSubstring("barfoothefoobarman", words);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    cout << endl;

    // words = vector<string>({"word","student"});
    // res = s.findSubstring("wordgoodstudentgoodword", words);
    // for (int i = 0; i < res.size(); ++i) {
    //     cout << res[i] << " ";
    // }
    // cout << endl;

    words = vector<string>({"bar","foo","the"});
    res = s.findSubstring("barfoofoobarthefoobarman", words);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}