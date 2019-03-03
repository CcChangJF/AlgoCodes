#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<int, long long> pil;
typedef std::pair<long long, long long> pll;

using namespace std;
const int INF = 0x3f3f3f3f;

const int N = 1001;
int board[N][N];
int speed[11];
queue<pii> qs[11];
const int NB = 4;
int nbs[4][2] = {
    {-1, 0},
    {1, 0},
    {0, 1},
    {0, -1}
};

bool isLegal(int r, int c, int rs, int cs) {
    if (r < 0 || c < 0 || r >= rs || c >= cs) { return false; }
    return true;
}

void bfs(int row, int col, int moves, int rows, int cols, int player, queue<pii> &qt) {
    // cout << row << ", " << col << ", " << player << endl;
    queue<pii> q;
    q.push(pii(row, col));
    for (int i = 0; i < moves; ++i) {
        int sz = q.size();
        if (0 == sz) { break; }
        for (int t = 0; t < sz; ++t) {
            // if (q.empty()) { return; }
            pii cur = q.front();
            q.pop();
            for (int j = 0; j < NB; ++j) {
                int r = cur.first + nbs[j][0];
                int c = cur.second + nbs[j][1];
                // cout << r << ", " << c << endl;
                if (isLegal(r, c, rows, cols) && 0 == board[r][c]) {
                    board[r][c] = player;
                    q.push(pii(r, c));
                    qt.push(pii(r, c));
                }
            }
        }
    }
    // for (int d = 0; d < rows; ++d) {
    //     for (int f = 0; f < cols; ++f) {
    //         cout << board[d][f] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
}


void run(int n, int m, int p) {
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            if (0 == board[r][c] || -1 == board[r][c]) { continue; }
            else {
                qs[board[r][c]].push(pii(r, c));
            }
        }
    }

    while(true) {
        bool flag = false;
        for (int i = 1; i <= p; ++i) {
            if (!qs[i].empty()) { flag = true; break; }
        }
        if (!flag) { break; }
        for (int i = 1; i <= p; ++i) {
            if (qs[i].empty()) { continue; }
            int sz = qs[i].size();
            for (int t = 0; t < sz; ++t) {
                pii cur = qs[i].front();
                qs[i].pop();
                int row = cur.first;
                int col = cur.second;
                bfs(row, col, speed[i], n, m, i, qs[i]);
                // for (int d = 0; d < n; ++d) {
                //     for (int f = 0; f < m; ++f) {
                //         cout << board[d][f] << " ";
                //     }
                //     cout << endl;
                // }
                // cout << endl;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,p;
    cin >> n >> m >> p;
    string s;
    for (int i = 1; i <= p; ++i) {
        cin >> speed[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (int j = 0; j < m; ++j) {
            if ('#' == s[j]) { board[i][j] = -1; }
            else {
                board[i][j] = '.' == s[j] ? 0 : s[j] - '0';
            }
        }
    }
    run(n, m, p);
    vector<int> ans(p + 1, 0);
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            if (-1 != board[r][c]) {
                ++ans[board[r][c]];
            }
        }
    }
    for (int i = 1; i <= p; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    
    


    return 0;
}