#define _USE_MATH_DEFINES
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
#include <math.h>

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<int, long long> pil;
typedef std::pair<long long, long long> pll;

using namespace std;
const int INF = 0x3f3f3f3f;

const int N = 10003;
const int maxN = 1 << 15;
int lens[N];
double ang[maxN];
double vx[maxN];
double vy[maxN];
double prevs[N];

void initSegTree(int cur, int l, int r) {
    vx[cur] = ang[cur] = 0;
    if (l > r - 1) { return; }
    else if (l == r - 1) {
        vy[cur] = lens[l];
    }
    else {
        int chl = 2 * cur;
        int chr = chl + 1;
        int mid = (l + r) / 2;
        initSegTree(chl, l, mid);
        initSegTree(chr, mid, r);
        vy[cur] = vy[chl] + vy[chr];
    }
}

void change(int s, double a, int v, int l, int r) {
    if (l <= s && s < r - 1) {
        int chl = 2 * v;
        int chr = chl + 1;
        int m = (l + r) / 2;
        change(s, a, chl, l, m);
        change(s, a, chr, m, r);
        if (s < m) { ang[v] += a; }
        // ang[v] += a;
        double si = sin(ang[v]);
        double co = cos(ang[v]);
        vx[v] = vx[chl] + (co * vx[chr] - si * vy[chr]);
        vy[v] = vy[chl] + (si * vx[chr] + co * vy[chr]);
        // printf("debug: %d, %d, %.2f, %.2f, %.2f\n", l, r, vx[v], vy[v], ang[v]);
        // getchar();
    }
    return; 
}

int main() {
    int n,c;
    while(cin >> n >> c) {
        for (int i = 1; i <= n; ++i) {
            cin >> lens[i];
        }
        initSegTree(1, 1, n + 1);
        for (int i = 1; i <= n; ++i) { prevs[i] = M_PI; }
        for (int i = 1; i <= c; ++i) {
            int s,a;
            cin >> s >> a;
            double angle = 2 * M_PI * a / 360;
            // cout << angle - prevs[s] << endl;
            change(s, angle - prevs[s], 1, 1, n + 1);
            prevs[s] = angle;
            printf("%.2f %.2f\n", vx[1], vy[1]);

            // printf("ang: %.2f", ang[1]);
        }
        printf("\n");
    }
    return 0;
}