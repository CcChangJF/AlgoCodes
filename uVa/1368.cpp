
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>


using namespace std;

class Solution{
public:
    int errors;
    string ans;
    void hamming(vector<string> &dnas) {
        errors = 0;
        if (0 == dnas.size()) { return; }
        int cols = dnas[0].size();
        int rows = dnas.size();
        vector<char> ansVec = vector<char>(cols, ' ');
        for (int col = 0; col < cols; ++col) {
            map<char, int> cnt = map<char, int>();
            for (int row = 0; row < rows; ++row) {
                ++cnt[dnas[row][col]];
            }
            int maxCnt = -1;
            char curChar = ' ';
            for (auto pair : cnt) {
                if (pair.second > maxCnt) {
                    maxCnt = pair.second;
                    curChar = pair.first;
                }
                else if (pair.second == maxCnt) {
                    curChar = (curChar <= pair.first) ? curChar : pair.first;
                }
            }
            ansVec[col] = curChar;
            errors += (rows - maxCnt);
        }
        ans = string(ansVec.begin(), ansVec.end());
        return;
    }
};

int main() {
    Solution s;
    int t;
    cin >> t;
    while (t--) {
        int rows, cols;
        cin >> rows >> cols;
        vector<string> dnas = vector<string>(rows, "");
        for (int i = 0; i < rows; ++i) {
            cin >> dnas[i];
        }
        s.hamming(dnas);
        cout << s.ans << endl;
        cout << s.errors << endl;
    }

    return 0;
}