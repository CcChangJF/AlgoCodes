
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (0 == num1.length() || 0 == num2.length()) { return "";}
        vector<int> multi = vector<int>(num1.length() + num2.length() + 2, 0);
        if (num1.length() > num2.length()) {
            swap(num1, num2);
        }
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for (int i = 0; i < num1.length(); ++i) {
            for (int j = 0; j < num2.length(); ++j) {
                int mlt = (num1[i] - '0') * (num2[j] - '0') + multi[i + j];
                multi[i + j] = mlt % 10;;
                multi[i + j + 1] += mlt / 10;
            }
        }
        string res = "";
        int cnt = multi.size();
        while (0 == multi[--cnt]) {
        }
        if (cnt < 0) {
            res = "0";
        }
        else {
            while (cnt >= 0) {
                res.push_back('0' + multi[cnt--]);
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.multiply("123", "456") << endl;

    return 0;
}