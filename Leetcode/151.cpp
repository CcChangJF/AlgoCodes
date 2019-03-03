
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
    void rev(string &s, int begin, int end) {
        int mid = begin + (end - begin) / 2;
        for (int i = begin; i <= mid; ++i) {
            swap(s[i], s[end - i + begin]);
        }
        return;
    }
public:
    void reverseWords(string &s) {
        if (0 == s.length()) { return ;}
        int start = 0;
        int begin = 0;
        int end = 0;
        int len = s.length();
        while (end < len) {
            while(end < len && ' ' == s[end]) { ++end;}
            begin = start;
            while(end < len && ' ' != s[end]) {
                s[start++] = s[end++];
            }
            // cout << "debug: " << begin << " " << start << endl;
            if (begin < start) {
               rev(s, begin, start - 1);
                // cout << s << endl;
                s[start++] = ' '; 
            }
        }
        if (0 == start) {
            s = "";
        }
        else {
            rev(s, 0, start - 2);
            s = s.substr(0, start - 1);
        }
        return;
    }
};

int main() {
    Solution s;

    string test = "";

    test = "  the sky    is blue  ";
    s.reverseWords(test);
    cout << test << endl;

    test = "the sky    is blue";
    s.reverseWords(test);
    cout << test << endl;

    test = "    ";
    s.reverseWords(test);
    cout << test << endl;
    return 0;
}