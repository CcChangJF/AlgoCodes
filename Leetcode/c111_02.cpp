
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        if (0 == A.size() || 0 == A[0].size()) { return 0;}
        int res = 0;
        vector<int> mark = vector<int>(A[0].size(), 0);
        for (int row = 1; row < A.size(); ++row) {
            for (int col = 0; col < A[0].size(); ++col) {
                if (!mark[col] && A[row][col] < A[row - 1][col]) {
                    mark[col] = 1;
                    ++res;
                }
            }
        }
        return res;
    }
};

int main() {

    return 0;
}