#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const int N = 1005;
int mark[N][N];
int bestDir[N][N];
int shortest = 2 * N;
int a1,b1,a2,b2,a3,b3;
int flag = -1;
int ansx[N];
int ansy[N];
// -2 -1 +2 +1. left up right down 


bool isSatisfied() {
    if (0 == mark[a1][b1] || 0 == mark[a2][b2] || 0 == mark[a3][b3]) { return false;}
    return true;
}

bool isLegal(int row, int col) {
    if (row < 0 || row > 1000 || col < 0 || col > 1000) { return false;}
    return true;
}

void bfs(int a, int b, int t) {
    memset(mark, 0, sizeof(mark));
    mark[a][b] = 3;
    queue<pair<int, int> > q;
    q.push(make_pair(a, b));
    int steps = 0;
    int cnt = 1;
    while(!q.empty() && !isSatisfied()) {
        ++steps;
        int count = 0;
        for (int i = 0; i < cnt; ++i) {
            pair<int,int> cur = q.front();
            q.pop();
            if (isLegal(cur.first - 1, cur.second) && 0 == mark[cur.first - 1][cur.second]) {
                mark[cur.first - 1][cur.second] = 1;
                q.push(make_pair(cur.first - 1, cur.second));
                ++count;
            }
            if (isLegal(cur.first + 1, cur.second) && 0 == mark[cur.first + 1][cur.second]) {
                mark[cur.first + 1][cur.second] = -1;
                q.push(make_pair(cur.first + 1, cur.second));
                ++count;
            }
            if (isLegal(cur.first, cur.second - 1) && 0 == mark[cur.first ][cur.second - 1]) {
                mark[cur.first][cur.second - 1] = 2;
                q.push(make_pair(cur.first, cur.second - 1));
                ++count;
            }
            if (isLegal(cur.first, cur.second + 1) && 0 == mark[cur.first ][cur.second + 1]) {
                mark[cur.first][cur.second + 1] = -2;
                q.push(make_pair(cur.first, cur.second + 1));
                ++count;
            }
        }  
        cnt = count;
    }
    if (isSatisfied() && steps < shortest) {
        shortest = steps;
        flag = t;
        memcpy(bestDir, mark, sizeof(mark));
    }
    return;
}

void getAns(int a, int b, int x, int y, int &cnt) {
    cout << "text: " << a << " " << b << " " << x << " " << y << " " << cnt << endl;
    cout  << "in ans: " << a1 << " " << b1 << " " << a2 << " " << b2 << " " << a3 << " " << b3 << endl;
    // for (int i = 0; i < 10; ++i) {
    //     for (int j = 0; j < 10; ++j) {
    //         cout << bestDir[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // getchar();
    int row = a;
    int col = b;
    while(row != x || col != y) {
        cout  << "in circle: " << row << ", " << col << " | " << a1 << " " << b1 << " " << a2 << " " << b2 << " " << a3 << " " << b3 << endl;
        // cout << row << " " << col << endl;
        if (row == 229 && col == 777) {
            cout << mark[row][col] << " | " << bestDir[row][col] << endl;
        }
        if (0 == mark[row][col]) {
            mark[row][col] = 1;
            ansx[cnt] = row;
            ansy[cnt++] = col;
        }
        
        switch(bestDir[row][col]) {
            case -2:
                --col;break;
            case -1:
                --row; break;
            case 2:
                ++col;break;
            case 1:
                ++row; break;
        }
    }
    cout  << "in ans1: " << a1 << " " << b1 << " " << a2 << " " << b2 << " " << a3 << " " << b3 << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    // cin.tie(0);
    cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;
    shortest = 2 * N;
    flag = -1;
    bfs(a1, b1, 1);
    // cout << shortest << endl;
    bfs(a2, b2, 2);
    // cout << "short: " << shortest << endl;
    bfs(a3, b3, 3);
    // cout << shortest << endl;
    cout << flag << " " << shortest << endl;
    memset(mark, 0, sizeof(mark));
    int cnt = 0;
    if (1 == flag) {
        cnt = 0;
        getAns(a2, b2, a1, b1, cnt);
        getAns(a3, b3, a1, b1, cnt);
        ansx[cnt] = a1;
        ansy[cnt++] = b1;
        // cout << cnt << endl;
    }
    else if (2 == flag) {
        cnt = 0;
        getAns(a1, b1, a2, b2, cnt);
        getAns(a3, b3, a2, b2, cnt);
        ansx[cnt] = a2;
        ansy[cnt++] = b2;
    }
    else if (3 == flag) {
        cout << a1 << " " << b1 << " " << a2 << " " << b2 << " " << a3 << " " << b3 << endl;
        cnt = 0;
        getAns(a1, b1, a3, b3, cnt);
        cout << a1 << " " << b1 << " " << a2 << " " << b2 << " " << a3 << " " << b3 << endl;
        getAns(a2, b2, a3, b3, cnt);
        ansx[cnt] = a3;
        ansy[cnt++] = b3;
    }
    cout << cnt << endl;
    for (int i = 0; i < cnt; ++i) {
        cout << ansx[i] << " " << ansy[i] << "\t";
    }

    return 0;
}