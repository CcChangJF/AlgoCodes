
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (0 == needle.size()) { return 0;}
        int patLen = needle.length();
        vector<vector<int> > match(patLen, vector<int>(128, 0));
        match[0][needle[0]] = 1;
        int curState = 0;
        for (int i = 1; i < patLen; ++i) {
            match[i] = vector<int>(match[curState].begin(), match[curState].end());
            match[i][needle[i]] = i + 1;
            curState = match[curState][needle[i]];
        }

        // for (int row = 0; row < patLen; ++row) {
        //     cout << needle[row] << " ";
        //     for (int col = 0; col < patLen; ++col) {
        //         cout << match[row][needle[col]] << " ";
        //     }
        //     cout << endl;
        // }
        
        int state = 0;
        for (int i = 0; i < haystack.size(); ++i) {
            state = match[state][haystack[i]];
            if (state == patLen) {
                return i - patLen;
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    cout << s.strStr("ABABABCDE", "ABABC") << endl;
    return 0;
}