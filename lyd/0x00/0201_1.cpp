#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const int N = 5;
int ans = 7;

void pushSwitch(int row, int col, int &state) {
    for (int r = max(0, row - 1); r <= min(N - 1, row + 1); ++r) {
        state = state ^ (1 << r * N + col); 
    }
    for (int c = max(0, col - 1); c <= min(N - 1, col + 1); ++c) {
        state = state ^ (1 << row * N + c);
    }
    state = state ^ (1 << row * N + col);
    return;
}

int getSteps(int s, int ori) {
    int res = 0;
    int curS = ori;
    int changedBit = (curS & 0x1f) ^ s;
    for (int b = 0; b < N; ++b) {
        if ((changedBit & 1 << b) > 0) {
            pushSwitch(0, b, ori);
            ++res;
        }
    }
    for (int row = 0; row < N - 1; ++row) {
        for (int col = 0; col < N; ++col) {
            if (0 == (ori & 1 << row * N + col)) {
                pushSwitch(row + 1, col, ori);
                ++res;
                if (res > 6) { break;}
            }
        }
        if (res > 6) { break; }
    }
    if (res <= 6 && 0x1f == ((ori >> N * N - N) & 0x1f)) {
        return res;
    }
    else {
        return 100;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        string s;
        int num = 0;
        for (int k = 0; k < N; ++k) {
            int cur = 0;
            cin >> s;
            for (int i = 0; i < N; ++i) {
                cur += ((s[i] - '0') << (N - i - 1));
            }
            num = num + (cur << k * N);
        }
        int all = 1 << N;
        ans = 7;
        for (int i = 0; i < all; ++i) {
            ans = min(ans, getSteps(i, num));
        }
        cout << (ans > 6 ? -1 : ans) << endl;
    }
    return 0;
}