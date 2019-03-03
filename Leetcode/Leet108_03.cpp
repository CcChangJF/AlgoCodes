#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        if (0 == A.size() || 0 == A[0].size()) {return 0;}
        vector<vector<int> > res(A.size(), vector<int>(A[0].size(), INT_MAX));
        for(int col = 0; col < A[0].size(); col = col + 1) {
            res[0][col] = A[0][col];
        }
        for(int row = 1; row < A.size(); row = row + 1) {
            for (int col = 0; col < A[row].size(); col = col + 1) {
                for(int k = max(0, col - 1); k <= min(col + 1, (int)A[row].size() - 1); k = k + 1) {
                    res[row][col] = min(res[row][col], A[row][col] + res[row - 1][k]);
                }
            }
        }
        int ret = INT_MAX;
        for (int col = 0; col < A[A.size()-1].size(); col = col + 1) {
            ret = min(ret, res[A.size()-1][col]);
        }
        return ret;
    }
};

int main() {

    return 0;
}