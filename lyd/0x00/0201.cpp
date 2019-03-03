#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const int N = 5;
int board[N][N];
int boardP[N][N];
int ans = INT_MAX;

void pushSwitch(int b[][N], int row, int col, int rows, int cols) {
    for (int r = max(0, row - 1); r <= min(rows - 1, row + 1); ++r) {
        b[r][col] = 1 ^ b[r][col];
    }
    for (int c = max(0, col - 1); c <= min(cols - 1, col + 1); ++c) {
        b[row][c] = 1 ^ b[row][c];
    }
    b[row][col] = 1 ^ b[row][col];
    return;
}

void dfs(int col, int cols, int rows, int steps) {
    if (col == cols) {
        memcpy(boardP, board, sizeof(board));
        for (int row = 0; row < rows - 1; ++row) {
            for (int c = 0; c < cols; ++c) {
                if (0 == boardP[row][c]) {
                    ++steps;
                    pushSwitch(boardP, row + 1, c, rows, cols);
                }
            }
        }
        bool flag = true;
        for (int c = 0; c < cols; ++c) {
            if (0 == boardP[rows - 1][c]) { 
                flag = false;
                break;
            }
        }
        if (flag && steps <= 6 && ans > steps) {
            ans = steps;
        }
        return;
    }
    dfs(col + 1, cols, rows, steps);
    pushSwitch(board, 0, col, rows, cols);
    dfs(col + 1, cols, rows, steps + 1);
    pushSwitch(board, 0, col, rows, cols);
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        string s;
        for (int i = 0; i < N; ++i) {
            cin >> s;
            for (int j = 0; j < N; ++j) {
                board[i][j] = '0' == s[j] ? 0 : 1;
            }
        }
        // pushSwitch(0, 0, N, N);
        // for (int i = 0; i < N; ++i) {
        //     for (int j = 0; j < N; ++j) {
        //         cout << board[i][j];
        //     }
        //     cout << endl;
        // }

        ans = INT_MAX;
        int rows = N;
        int cols = N;
        dfs(0, cols, rows, 0);
        if (ans == INT_MAX) {
            ans = -1;
        }
        cout << ans << endl;
    }


    return 0;
}