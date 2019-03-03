#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (0 == s.size()) {return true;}
        stack<char> stk = stack<char>();
        for (int i = 0; i < s.length(); ++i) {
            if ('(' == s[i] || '[' == s[i] || '{' == s[i]) {
                stk.push(s[i]);
            }
            else if (')' == s[i] || ']' == s[i] || '}' == s[i]) {
                if (stk.empty()) {
                    return false;
                }
                char c = stk.top();
                stk.pop();
                if (')' == s[i] && c == '(') {
                    continue;
                }
                else if (']' == s[i] && '[' == c) {
                    continue;
                }
                else if ('}' == s[i] && '{' == c) {
                    continue;
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
        }
        if (stk.empty()) {
            return true;
        }
        else {
            return false;
        }
    }
};

int main() {
    Solution s;
    cout << s.isValid("()") << endl;
    cout << s.isValid("(") << endl;
    cout << s.isValid(")") << endl;

    return 0;
}