
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
    bool valid(string s, int start, int end) {
        if (start >= end) {return false;}
        if ('0' == s[start] && (start + 1 != end)) {
            return false;
        }
        int num = 0;
        for (int i = start; i < end; ++i) {
            num = num * 10 + s[i] - '0';
            if (num > 255 || num < 0) {
                return false;
            }
        }
        return true;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res = vector<string>();
        if (0 == s.length() || s.length() > 12) { return res; }
        int start = 0;
        int end = s.length();
        for (int i = start + 1; i < end - 2;  ++i) {
            for (int j = i + 1; j < end - 1; ++j) {
                for (int k = j + 1; k < end; ++k) {
                    if (valid(s, start, i) && valid(s, i, j) 
                        && valid(s, j, k) && valid(s, k, end)) {
                        string str = string(s);
                        str.insert(str.begin() + k, '.');
                        str.insert(str.begin() + j, '.');
                        str.insert(str.begin() + i, '.');
                        res.push_back(str);
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    // length = 0 & length > 12
    return 0;
}