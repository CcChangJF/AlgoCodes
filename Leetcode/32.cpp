//Description



//TestCase
/*

*/

//Wrong case
/*

*/


/*
how to solve


*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;


class Solution {
public:
    int longestValidParentheses(string s) {
        if (0 == s.length()) {return 0;}
        stack<int> stk = stack<int>();
        stk.push(-1);
        int ans = 0;
        for (int i = 0; i < s.length(); ++i) {
            if ('(' == s[i]) {
                stk.push(i);
            }
            else if (')' == s[i]) {
                stk.pop();
                if (stk.empty()) {
                    stk.push(i);
                }
                else {
                    ans = max(ans, i - stk.top());
                }
            }
        }
        return ans;
    }
};


class Solution1 {
public:
    int longestValidParentheses(string s) {
        if (0 == s.length()) { return 0;}
        stack<int> stk = stack<int>();
        vector<int> dp = vector<int>(s.size(),0);
        for (int i = 0; i < s.length(); ++i) {
            if ('(' == s[i]) {
                dp[i] = 0;
                stk.push(i);
            }
            else if (')' == s[i]) {
                if (stk.empty()) {
                    dp[i] = 0;
                }
                else {
                    int index = stk.top();
                    if ('(' == s[index]) {
                        stk.pop();
                        dp[i] = i - index + 1;
                        if (index - 1 >= 0) {
                            dp[i] += dp[index - 1];
                        }
                    }
                }
            }
            else {
                return 0;
            }
        }
        int longest = 0;
        for (int i = 0; i < dp.size(); ++i) {
            longest = max(longest, dp[i]);
        }
        return longest;
    }
};

int main() {
    Solution s;
    cout << s.longestValidParentheses("()()") << endl;
    cout << s.longestValidParentheses(")))()(((())))") << endl;
    cout << s.longestValidParentheses("((()((())") << endl;
    cout << s.longestValidParentheses("((()))") << endl;

    return 0;
}