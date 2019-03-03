#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<int, long long> pil;
typedef std::pair<long long, long long> pll;

using namespace std;
const int INF = 0x3f3f3f3f;

const int N = 1000;
int board[N][N];
bool visit[N][N];
pii blacks[700];
pair<pii, int> dis[N];
pii ans[2003];
int rs[N];
int cs[N];

bool islegal(int r, int c, int rows, int cols) {
    if (r < 0 || r >= rows || c < 0 || c >= cols) { return false; }
    return true;
}

int getBlacks(int x, int y, int destx, int desty, int rows, int cols) {
    int sx = min(x, destx);
    int ex = max(x, destx);
    int sy = min(y, desty);
    int ey = max(y, desty);
    int ans = 0;
    for (int r = sx; r <= ex; ++r) {
        for (int c = 0; c <= cols; ++c) {
            if (1 == board[r][c]) { ++ans; }
        }
    }
    for (int r = 0; r < cols; ++r) {
        if (r >= sx && r <= ex) { continue; }
        for (int c = sy; c <= ey; ++c) {
            if (1 == board[r][c]) { ++ans; }
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    // cin.tie(0);
    int x,y;
    x = 999;
    y = 999;
    // scanf("%d %d", &x, &y);
    int wx,wy,bx,by;
    scanf("%d %d", &wx, &wy);
    board[wx][wy] = 2;
    for (int i = 0; i < 666; ++i) {
        scanf("%d %d", &bx, &by);
        ++rs[bx];
        ++cs[by];
        board[bx][by] = 1;
        blacks[i].first = bx;
        blacks[i].second = by;
    }
    int destx, desty;
    queue<pii> q;
    q.push(pii(wx, wy));
    visit[wx][wy] = 1;
    while(!q.empty()) {
        pii cur = q.front();
        q.pop();
        // int moves = getBlacks(wx, wy, cur.first, cur.second, x, y);
        int moves = 0;
        for (int r = min(wx, cur.first); r <= max(wx, cur.first); ++r) {
            moves += rs[r];
            for (int c = min(wy, cur.second, c <= max(wy, cur.second)); ++c) {
                if(1 == board[r][c]) { --moves;}
            }
        }
        for (int c = min(wy, cur.second, c <= max(wy, cur.second)); ++c) {
            moves += cs[c];
        }
        // if (moves > max(abs(wx - cur.first), abs(wy - cur.second))) {
        //     destx = cur.first;
        //     desty = cur.second;
        //     break;
        // }
        for (int i = -1; i <= 1; ++i) {
            for(int j = -1; j <= 1; ++j) {
                if (0 == i && 0 == j) { continue; }
                int newx = cur.first + i;
                int newy = cur.second + j;
                if (0 != visit[newx][newy] || !islegal(newx, newy, x, y)) { continue; }
                q.push(pii(newx, newy));
                visit[newx][newy] = 1;
            }
        }
    }
    int cnt = 0;
    int tx = 1;
    int ty = 1;
    if (destx < wx) { tx = -1; }
    if (desty < wy) { ty = -1; }
    int dx = abs(destx - wx);
    int dy = abs(desty - wy);
    int d = 1;
    for (; d < min(dx, dy); ++d) {
        ans[cnt++] = pii(wx + tx * d, wy + ty * d);
    }
    if (destx != wx) {
        for (; d < max(dx, dy); ++d) {
            ans[cnt++] = pii(wx + tx * d, wy);
        }
    }
    if (desty != wy) {
        for (; d < max(dx, dy); ++d) {
            ans[cnt++] = pii(wx, wy + tx * d);
        }
    }
    int curAns = 0;
    int k = 0;
    while(curAns < cnt) {
        printf("%d %d\n", ans[curAns].first, ans[curAns].second);
        fflush(stdout);
        scanf("%d %d %d", &k, &x, &y);
        if (-1 == k || -1 == x || -1 == y) {
            break;
        }
        if (0 == k || 0 == x || 0 == y) {
            break;
        }
        ++curAns;
    }

    return 0;
}