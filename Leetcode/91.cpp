
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (0 == s.length()) { return 0;}
        vector<int> dp = vector<int>(s.length() + 1, 0);
        dp[0] = 1;
        dp[1] = ('0' == s[0]) ? 0 : 1;
        for (int i = 1; i < s.length(); ++i) {
            if (((s[i - 1] > '2' || '0' == s[i - 1]) && '0' == s[i]) 
                || (s[i] < '0' || s[i] > '9')) {
                return 0;
            }
            if ('0' == s[i]) {
                dp[i + 1] = dp[i - 1];
            }
            else {
                int num = (s[i -1] - '0') * 10 + (s[i] - '0');
                if (10 <= num && num <= 26) {
                    dp[i + 1] = dp[i - 1] + dp[i];
                }
                else {
                    dp[i + 1] = dp[i];
                }
            }
        }
        return dp[s.length()];
    }
};

int main() {
    // empty
    // s[i] == 0 || s[i] is not dight
    // s[i][i-1] is larger that 26
    // '0'
    Solution s;
    cout << s.numDecodings("12345") << endl;
    cout << s.numDecodings("1020") << endl;
    return 0;
}