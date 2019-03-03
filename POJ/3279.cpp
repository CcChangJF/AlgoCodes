
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <bitset>
#include <cmath>
#include <climits>

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<int, long long> pil;
typedef std::pair<long long, long long> pll;

using namespace std;
const int INF = 0x3f3f3f3f;

const int N = 15;
int board[N][N];
int aux[N][N];
int flipBoard[N][N];
int ans[N][N];

bool isLegal(int row, int col, int m, int n) {
    if (row >= m || col >= n || row < 0 || col < 0) { return false; }
    else return true;
}

bool lessThan(int m, int n) {
    for (int row = 0; row < m; ++row) {
        for (int col = 0; col < n; ++col) {
            if (flipBoard[row][col] != ans[row][col]) {
                return flipBoard[row][col] < ans[row][col];
            }
        }
    }
    return false;
}

void flipTile(int row, int col, int m, int n) {
    aux[row][col] = 1 - aux[row][col];
    if (isLegal(row - 1, col, m, n)) { aux[row - 1][col] = 1 - aux[row - 1][col]; }
    if (isLegal(row + 1, col, m, n)) { aux[row + 1][col] = 1 - aux[row + 1][col]; }
    if (isLegal(row, col - 1, m, n)) { aux[row][col - 1] = 1 - aux[row][col - 1]; }
    if (isLegal(row, col + 1, m, n)) { aux[row][col + 1] = 1 - aux[row][col + 1]; }
    return;
}

int getFlips(int m, int n, int s, int minFlips) {
    memcpy(aux, board, sizeof(aux));
    memset(flipBoard, 0, sizeof(flipBoard));

    int numberOfFlips = 0;
    for (int col = 0; col < n; ++col) {
        if ((s >> col & 1) != aux[0][col]) {
            ++numberOfFlips;
            flipBoard[0][col] = 1;
            flipTile(0, col, m, n);
        }
    }
    
    for (int row = 0; row < m - 1; ++row) {
        for (int col = 0; col < n; ++col) {
            if (1 == aux[row][col]) {
                   
                ++numberOfFlips;
                flipBoard[row + 1][col] = 1;
                if (numberOfFlips > minFlips) { return INF; }
                flipTile(row + 1, col, m, n);
            }
        }
    }
    for (int col = 0; col < n; ++col) {
        if (1 == aux[m - 1][col]) { return INF;}
    }

    return numberOfFlips;
}

int main() {
    int m,n;
    cin >> m >> n;
    for (int row = 0; row < m; ++row) {
        for (int col = 0; col < n; ++col) {
            cin >> board[row][col];
        }
    }
    int all = 1 << n;
    int minFlips = INF;
    for (int i = 0; i < all; ++i) {
        int flips = getFlips(m, n, i, minFlips);
        if (flips < minFlips) {
            minFlips = flips;
            memcpy(ans, flipBoard, sizeof(ans));
        }
        else if (flips == minFlips && lessThan(m, n)) {
            memcpy(ans, flipBoard, sizeof(ans));
        }
    }
    if (INF == minFlips) {
        cout << "IMPOSSIBLE" << endl;
    }
    else {
        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                cout << ans[row][col] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}