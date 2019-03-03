#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

class Solution{
    void shift(vector<vector<int> > &board, int row, int n) {
        int last = board[row][n - 1];
        for (int i = n - 1; i > 0; --i) {
            board[row][i] = board[row][i - 1];
        }
        board[row][0] = last;
        return;
    }
    int dfs(vector<vector<int> > &board, vector<int> &sum, int n, int cur) {
        if (cur == n) {
            int maxSum = 0;
            for (int col = 0; col < n; ++col) {
                int sum = 0;
                for (int row = 0; row < n; ++row) {
                    // cout << board[row][col] << " ";
                    sum += board[row][col];
                }
                maxSum = max(maxSum, sum);
                // cout << endl;
            }
            // cout << "max: " << maxSum << endl;
            return maxSum;
        }
        else {
            int minSum = INT_MAX;
            for (int i = 0; i < n; ++i) {
                bool needDfs = true;
                for (int k = 0; k < n; ++k) {
                    sum[k] += board[cur][k];
                    if (sum[k] >= minSum) {
                        for (int t = 0; t <= k; ++t) {
                            sum[t] -= board[cur][t];
                        }
                        needDfs = false;
                        break;
                    }
                }
                if (needDfs) {
                    minSum = min(minSum, dfs(board, sum, n, cur + 1));
                    shift(board, cur, n);
                }
                
            }
            return minSum;
        }
    }
public:
    int minMax(vector<vector<int> > &board, int n) {
        if (1 == n) { return board[0][0];}
        vector<int> sum = vector<int>(n, 0);
        for (int i = 0; i < n; ++i) {
            sum[i] = board[0][i];
        }
        return dfs(board, sum, n, 1);
    }
};

int main() {
    Solution s;
    int n;
    cin >> n;
    while (-1 != n) {
        vector<vector<int> > board(n, vector<int>(n, 0));
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                cin >> board[row][col];
            }
        }
        cout << s.minMax(board, n) << endl;
        cin >> n;
    }

    return 0;
}