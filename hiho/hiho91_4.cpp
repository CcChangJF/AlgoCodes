#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<int, long long> pil;
typedef std::pair<long long, long long> pll;

using namespace std;
const int INF = 0x3f3f3f3f;

const int N = 1001;
int board[N][N];
const int NBS = 4;
int nbs[4][2] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};

bool isTwo(int row, int col, int h, int w) {
    if (col + 1 < w && 0 == board[row][col + 1]) {
        int cnt = 0;
        while(col < w && 0 == board[row][col]) {++col; ++cnt; }
        if (cnt < 3) { return false; }
        --col;
        int cnt1 = cnt;
        while(row < h && 0 == board[row][col]) { ++row; --cnt1;}
        --row;
        if (0 != cnt1) { return false; }
        cnt1 = cnt;
        while(col >= 0 && 0 == board[row][col]) { --col; --cnt1; }
        ++col;
        if (0 != cnt1) { return false; }
        cnt1 = cnt;
        while(row < h && 0 == board[row][col]) { ++row; --cnt1; }
        --row;
        if (0 != cnt1) { return false; }
        cnt1 = cnt;
        while(col < w && 0 == board[row][col]) { ++col; --cnt1; }
        --col;
        if (0 != cnt1) { return false; }
        return true;
    }
    else if (row + 1 < h && 0 == board[row + 1][col]) {
        int cnt = 0;
        int oriRow = row;
        while(row < w && 0 == board[row][col]) { ++cnt; ++row; }
        if (cnt < 3) { return false; }
        --row;
        int cnt1 = cnt;
        row = oriRow;
        while(col < w && 0 == board[row][col]) { ++col; --cnt1; }
        --col;
        if (0 != cnt1) { return false; }
        cnt1 = cnt;
        while(row < h && 0 == board[row][col]) { ++row; --cnt1; }
        --row;
        if (0 != cnt1) { return false; }
        cnt1 = cnt;
        while(col < w && 0 == board[row][col]) { ++col; --cnt1; }
        --col;
        if (0 != cnt1) { return false; }
        cnt1 = cnt;
        while(row >= 0 && 0 == board[row][col]) { --cnt1; --row; }
        ++row;
        if (0 != cnt1) { return false; }
        return true;
    }
    return false;
}

void paint(int row, int col, int h, int w) {
    if (row < 0 || row >= h || col < 0 || col >= w) { return; }
    if (1 == board[row][col]) { return; }
    board[row][col] = 1;
    for (int i = 0; i < NBS; ++i) {
        // cout << row + nbs[i][0] << ", " << col + nbs[i][1] << endl;
        paint(row + nbs[i][0], col + nbs[i][1], h, w);
    }
}


bool isFive(int row, int col, int h, int w) {
    if (col + 1 < w && 0 == board[row][col + 1]) {
        int oriCol = col;
        int cnt = 0;
        while(col < w && 0 == board[row][col]) {++col; ++cnt; }
        if (cnt < 3) { return false; }
        --col;
        int cnt1 = cnt;
        col = oriCol;
        while(row < h && 0 == board[row][col]) { ++row; --cnt1;}
        --row;
        if (0 != cnt1) { return false; }
        cnt1 = cnt;
        while(col < w && 0 == board[row][col]) { ++col; --cnt1; }
        --col;
        if (0 != cnt1) { return false; }
        cnt1 = cnt;
        while(row < h && 0 == board[row][col]) { ++row; --cnt1; }
        --row;
        if (0 != cnt1) { return false; }
        cnt1 = cnt;
        while(col >= 0 && 0 == board[row][col]) { --col; --cnt1; }
        ++col;
        if (0 != cnt1) { return false; }
        return true;
    }
    else if (row + 1 < h && 0 == board[row + 1][col]) {
        int cnt = 0;
        while(row < w && 0 == board[row][col]) { ++cnt; ++row; }
        if (cnt < 3) { return false; }
        --row;
        int cnt1 = cnt;
        while(col < w && 0 == board[row][col]) { ++col; --cnt1; }
        --col;
        if (0 != cnt1) { return false; }
        cnt1 = cnt;
        while(row >= 0 && 0 == board[row][col]) { --row; --cnt1; }
        ++row;
        if (0 != cnt1) { return false; }
        cnt1 = cnt;
        while(col < w && 0 == board[row][col]) { ++col; --cnt1; }
        --col;
        if (0 != cnt1) { return false; }
        cnt1 = cnt;
        while(row < w && 0 == board[row][col]) { --cnt1; ++row; }
        --row;
        if (0 != cnt1) { return false; }
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    // scanf("%d", &t);
    cin >> t;
    while(t--) {
         int w,h;
         // scanf("%d %d", &w, &h);
         cin >> w >> h;
         string s;
         for (int i = 0; i < h; ++i) {
            cin >> s;
            for (int j = 0; j < w; ++j) {
                board[i][j] = ('#' == s[j]) ? 0 : 1;
            }
         }
         // cout << "aaa" << endl;
         int cnt2 = 0;
         int cnt5 = 0;
         for (int row = 0; row < h; ++row) {
            for (int col = 0; col < w; ++col) {
                if (0 == board[row][col]) {
                    if (isTwo(row, col, h, w)) { ++cnt2; }
                    else if(isFive(row, col, h, w)) { ++cnt5; }
                    // cout << cnt2 << " " << cnt5 << endl;
                    paint(row, col, h, w);
                    // cout << "paint" << endl;
                    // for (int i = 0; i < h; ++i) {
                    //     for (int j = 0; j < w; ++j) {
                    //         cout << board[i][j];
                    //     }
                    //     cout << endl;
                    // }
                    // cout << endl;
                }
            }
         }
         cout << cnt2 << " " << cnt5 << endl;
    }

    return 0;
}