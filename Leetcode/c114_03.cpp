
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
    // ["abx","agz","bgc","bfc"]
    bool getDel(vector<string> &A, int srow, int erow, int col) {
        // for (int col = scol; col < cols; ++col) {
        //     if (del[col]) { continue; }
        if (col >= cols) { return true;}
        if (del[col]) {
            getDel(A, srow, erow, col + 1);
            return true;
        }
        bool ok = true;
        for (int row = srow + 1; row < erow; ++row) {
            if (A[row - 1][col] > A[row][col]) {
                del[col] = true;
                ok = false;
                break;
            }
        }
        if (ok) {
            for (int row = srow + 1; row < erow; ++row) {
                if (A[row - 1][col] == A[row][col]) {
                    int curStart = row - 1;
                    while (row < erow && A[row - 1][col] == A[row][col]) {
                        ++row;
                    }
                    // cout << curStart << " " << row << endl;
                    getDel(A, curStart, row, col + 1);
                    --row;
                }
            }
        }
        else {
            getDel(A, srow, erow, col + 1);
        }                       
        // }
        return true;
    }
public:
    int rows;
    int cols;
    int total;
    vector<bool> del;
    int minDeletionSize(vector<string>& A) {
        if (A.size() <= 1) { return 0;}
        int res = 0;
        rows = A.size();
        cols = A[0].length();
        total = 0;
        del = vector<bool>(cols, false);
        getDel(A, 0, rows, 0);
        for (int i = 0; i < cols; ++i) {
            if (del[i]) {
                ++total;
            }
        }
        return total;
    }
};

//["abx","agz","bgc","bfc"]
int main() {
    Solution s;
    vector<string> test;

    // test = vector<string>({"ca","bb","ac"});
    // cout << s.minDeletionSize(test) << endl;

    // test = vector<string>({"xc","yb","za"});
    // cout << s.minDeletionSize(test) << endl;

    // test = vector<string>({"zyx","wvu","tsr"});
    // cout << s.minDeletionSize(test) << endl;

    test = vector<string>({"abx","agz","bgc","bfc"});
    cout << s.minDeletionSize(test) << endl;

    test = vector<string>({"bwwdyeyfhc","bchpphbtkh","hmpudwfkpw","lqeoyqkqwe","riobghmpaa","stbheblgao","snlaewujlc","tqlzolljas","twdkexzvfx","wacnnhjdis"});
    cout << s.minDeletionSize(test) << endl;
    return 0;
}