#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
private:
    string getChars(int x) {
        if (2 <= x && x <= 6) {
            string str = "";
            for (int i = 0; i < 3; ++i) {
                str.push_back('a' + (x - 2) * 3 + i);
            }
            return str;
        }
        else if (7 == x) {
            return "pqrs";
        }
        else if ( 8 == x) {
            return "tuv";
        }
        else if (9 == x) {
            return "wxyz";
        }
        return "";
    }
    void dfs(string digits, vector<string> &res, int index, string cur) {
        if (index == digits.length()) {
            res.push_back(cur);
        }
        else {
            int digit = digits[index] - '0';
            string str = getChars(digit);
            for (int i = 0; i < str.length(); ++i) {
                cur.push_back(str[i]);
                dfs(digits, res, index + 1, cur);
                cur.pop_back();
            }
        }
        return;
    }
public:
    vector<string> letterCombinations(string digits) {
        if (0 == digits.size()) { return vector<string>();}
        vector<string> res = vector<string>();
        string cur = "";
        dfs(digits, res, 0, cur);
        return res;
    }
};

int main() {
    Solution s;
    vector<string> res = s.letterCombinations("234");
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << "\t";
    }
    cout << endl;
    return 0;
}