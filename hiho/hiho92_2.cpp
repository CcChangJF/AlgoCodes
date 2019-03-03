#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<int, long long> pil;
typedef std::pair<long long, long long> pll;

using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 103;
int board[N][N];
const int NBS = 4;
int nbs[4][2] = {{-1,0},{1,0},{0, -1 },{0, 1}};

bool isLegal(int r, int c, int rs, int cs) {
    if (r < 0 || r >= rs || c < 0 || c >= cs) { return false; }
    return true;
}

void bfs(pii start, int n) {
    queue<pii> q;
    q.push(start);
    while(!q.empty()) {
        pii cur = q.front();
        q.pop();
        for (int j = 0; j < NBS; ++j) {
            int r = cur.first + nbs[j][0];
            int c = cur.second + nbs[j][1];
            if (isLegal(r, c, n, n) && 0 == board[r][c]) {
                board[r][c] = board[cur.first][cur.second] + 1;
                q.push(pii(r, c));
            }
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pii> cities;
    pii start;
    for (int i = 0; i < n; ++i) {
        string str;
        cin >> str;
        for (int j = 0; j < n; ++j) {
            if ('C' == str[j]) { 
                start.first = i;
                start.second = j;
                board[i][j] = 1;
            }
            if ('c' == str[j]) { 
                cities.push_back(pii(i, j));
                board[i][j] = 0;
            }
            if ('#' == str[j]) { board[i][j] = -1;}
            board[i][j] = 0;
        }
    }
    bfs(start, n);
    int sz = cities.size();
    int ans = 0;
    for (int i = 0; i < sz; ++i) {
        ans += board[cities[i].first][cities[i].second];
    }
    cout << ans - sz - 1 << endl;

    return 0;
}