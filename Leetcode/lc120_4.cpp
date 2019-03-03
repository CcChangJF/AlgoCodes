#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<int, long long> pil;
typedef std::pair<long long, long long> pll;

using namespace std;
const int INF = 0x3f3f3f3f;

const int N = 1 << 20;
int dp[N][20];
class Solution {
    bool isLegal(int r, int c, int rs, int cs) {
        if (r < 0 || r >= rs || c < 0 || c >= cs) {
            return false;
        }
        return true;
    }
public:
    int rows,cols;
    // const static int N = 1 << 20;
    // int dp[N][20];
    int uniquePathsIII(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        int state = 0;
        int start = 0;
        int end = 0;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (1 == grid[row][col] || -1 == grid[row][col]) { state += (1 << row * cols + col); }
                if (1 == grid[row][col]) {
                    start = row * cols + col;
                }
                else if (2 == grid[row][col]) {
                    grid[row][col] = 0;
                    end = row * cols + col;
                }
            }
        }
        // cout << state << ", " << start << ", " << end << endl;
        memset(dp,0,sizeof(dp));
        int n = rows * cols;
        int all = 1 << n;
        // vector<vector<int> > dp(all, vector<int>(n, 0));
        dp[state][start] = 1;
        // cout << all << endl;
        for (int i = state; i < all; ++i) {
            // cout << bitset<12>(i) << ": ";
            for (int j = 0; j < n; ++j) {
                int r = j / cols;
                int c = j % cols;
                if ((i & 1 << j) > 0 && 0 == grid[r][c]) {
                    int up = (r - 1) * cols + c;
                    if (isLegal(r - 1, c, rows, cols) && 0 != dp[i ^ 1 << j][up]) {
                        dp[i][j] += dp[i ^ 1 << j][up];
                    }
                    int down = (r + 1) * cols + c;
                    if (isLegal(r + 1, c, rows, cols) && 0 != dp[i ^ 1 << j][down]) {
                        dp[i][j] += dp[i ^ 1 << j][down];
                    }

                    int left = r * cols + c - 1;
                    if (isLegal(r, c - 1, rows, cols) && 0 != dp[i ^ 1 << j][left]) {
                        dp[i][j] += dp[i ^ 1 << j][left];
                    }

                    int right = r * cols + c + 1;
                    if (isLegal(r, c + 1, rows, cols) && 0 != dp[i ^ 1 << j][right]) {
                        dp[i][j] += dp[i ^ 1 << j][right];
                    }
                }
                // cout << dp[i][j] << " ";
            }
            // cout << endl;
        }      
        return dp[all - 1][end];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution s;
    vector<vector<int> > test;

    test = vector<vector<int> >({
        {1,0,0,0},{0,0,0,0},{0,0,2,-1}
    });
    cout << s.uniquePathsIII(test) << endl;

    test = vector<vector<int> >({
        {1,0,0,0},{0,0,0,0},{0,0,0,2}
    });
    cout << s.uniquePathsIII(test) << endl;

    test = vector<vector<int> >({
        {0, 1}, {2,0}
    });
    cout << s.uniquePathsIII(test) << endl;

    test = vector<vector<int> >({
        {1,0}, {0,2}
    });
    cout << s.uniquePathsIII(test) << endl;


    test = vector<vector<int> >({
        {1,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,2}
    });
    cout << s.uniquePathsIII(test) << endl;


    return 0;
}