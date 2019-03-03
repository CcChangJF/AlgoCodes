#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const int N = 501;
int board[N][N];
int dest[N][N];
int arr[N * N + 1];

int lowbit(int x) {
    return x & (-x);
    // return x & (x ^ x - 1);
}

void addToTree(int k, int n) {
    while(k < n * n) {
        ++arr[k];
        k = k + lowbit(k);
    }
    return;
}

int getCount(int k) {
    int cnt = 0;
    while(k > 0) {
        cnt += arr[k];
        k = k - lowbit(k);
    }
    return cnt;
}

int getRevParity(int board[N][N], int n) {
    int ans = 0;
    memset(arr, 0, sizeof(arr));
    int zero = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (0 != board[i][j]) {
                addToTree(board[i][j], n);
                ans = (ans + i * N + j + 1 - zero - getCount(board[i][j])) & 1;
            }
            else {
                zero = 1;
            }
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin >> n && 0 != n) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> board[i][j];
            }
        }
        int parOri = getRevParity(board, n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> dest[i][j];
            }
        }
        int parDest = getRevParity(dest, n);
        if (parOri == parDest) {
            cout << "TAK" << endl;
        }
        else {
            cout << "NIE" << endl;
        }
    }


    return 0;
}