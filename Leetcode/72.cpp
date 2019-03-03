
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        if (0 == word1.length()) { return word2.length();}
        if (0 == word2.length()) { return word1.length();}
        vector<int> prev = vector<int>(word2.length() + 1,0);
        for (int i = 0; i <= word2.length(); ++i) {
            prev[i] = i;
        }
        vector<int> cur = vector<int>(word2.length() + 1,0);
        for (int row = 1; row <= word1.length(); ++row) {
            cur[0] = row;
            for (int col = 1; col <= word2.length(); ++col) {
                if (word1[row - 1] == word2[col - 1]) {
                    cur[col] = prev[col - 1];
                }
                else {
                    cur[col] = min(prev[col], prev[col - 1]);
                    cur[col] = min(cur[col], cur[col - 1]) + 1;
                }
            }
            prev = cur;
        }
        return cur[word2.length()];
    }
};

int main() {

    return 0;
}