
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
    int cmp(string &a, string &b) {
        int len = min(a.length(), b.length());
        for (int i = 0; i < len; ++i) {
            if (a[i] != b[i]) {
                return b[i] - a[i];
            }
        }
        if (a.length() == b.length()) { return 0;}
        else {
            return b.length() - a.length();
        }
    }
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char, char> trans = map<char, char>();
        for (int i = 0; i < order.length(); ++i) {
            trans[order[i]] = i + 'a';
        }
        string first = words[0];
        for (int i = 0; i < first.length(); ++i) {
            first[i] = trans[first[i]];
        }
        for (int i = 1; i < words.size(); ++i) {
            string cur = words[i];
            for (int j = 0; j < cur.length(); ++j) {
                cur = trans[cur[j]];
            }
            if (cmp(first, cur) < 0) {
                return false;
            }
            first = cur;
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<string> test;

    test = vector<string>({"hello","leetcode"});
    cout << s.isAlienSorted(test, "hlabcdefgijkmnopqrstuvwxyz") << endl;

    test = vector<string>({"word","world","row"});
    cout << s.isAlienSorted(test, "worldabcefghijkmnpqstuvxyz") << endl;


    test = vector<string>({"apple","app"});
    cout << s.isAlienSorted(test, "abcdefghijklmnopqrstuvwxyz") << endl;
    return 0;
}