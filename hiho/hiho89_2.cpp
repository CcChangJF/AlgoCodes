#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const int N = 1005;
int board[N][N];
int aux[N][N];
bool mark[N][N];
bool markRow[N];
int height[N][N];
queue<pair<int, int> > q;

bool isLegal(int row, int col, int n) {
    if (row < 0 || row >= n || col < 0 || col >= n) { return false;}
    else return true;
}

void adj(int row, int col, int n, int curHeight) {
    if (isLegal(row - 1, col, n) && !mark[row - 1][col]) { 
        mark[row - 1][col] = true;
        height[row - 1][col] = curHeight + 1;
        q.push(make_pair(row - 1, col));
    }
    if (isLegal(row + 1, col, n) && !mark[row + 1][col]) { 
        mark[row + 1][col] = true;
        height[row + 1][col] = curHeight + 1;
        q.push(make_pair(row + 1, col));
    }
    if (isLegal(row, col + 1, n) && !mark[row][col + 1]) { 
        mark[row][col + 1] = true;
        height[row][col + 1] = curHeight + 1;
        q.push(make_pair(row, col + 1));
    }
    if (isLegal(row, col - 1, n) && !mark[row][col - 1]) { 
        mark[row][col - 1] = true;
        height[row][col - 1] = curHeight + 1;
        q.push(make_pair(row, col - 1));
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (int j = 0; j < n; ++j) {
            board[i][j] = ('0' == s[j]) ? 0 : 1;
        }
        markRow[i] = true;
    }

    // n = 1000;
    // for (int row = 0; row < n; ++row) {
    //     for (int col = 0; col < n; ++col) {
    //         board[row][col] = 1;
    //     }
    // }
    // board[0][0] = 0;
    memset(height, 0x3f, sizeof(height));
    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < n; ++col) {
            if (0 == board[row][col]) {
                height[row][col] = 0;
                mark[row][col] = true;
                // markRow[row] = true;
                q.push(make_pair(row, col));
            }
        }
    }
    int curHeight = 0;
    while(!q.empty()) {
        memcpy(aux, height, sizeof(aux));
        // memset(markRow, 0, sizeof(markRow));
        int sz = q.size();
        for (int i = 0; i < sz; ++i) {
            pair<int, int> cur = q.front();
            q.pop();
            int row = cur.first;
            int col = cur.second;
            adj(row, col, n, curHeight);
        }
        ++curHeight;
        // for (int row = 0; row < n; ++row) {
        //     for (int col = 0; col < n; ++col) {
        //         cout << height[row][col] << "\t";
        //     }
        //     cout << endl;
        //     // getchar();
        // }
        // cout << endl;
    }
    int ans = 0;
    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < n; ++col) {
            // cout << height[row][col] << "\t";
            if (height[row][col] > ans) {
                ans = height[row][col];
            }
        }
        // getchar();
    }
    cout << ans << endl;

    return 0;
}