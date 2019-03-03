
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

const int N = 5003;
int facing[N];
int f[N];
//1101011
//1010

int getMinOper(int k, int n) {
    // cout << k << endl;
    int sum = 0;
    int res = 0;
    for (int i = 0; i <= n - k; ++i) {
        f[i] = 0;
        // cout << i << ", " << sum << ", " << facing[i] << ",";
        if (1 == (facing[i] + sum & 1)) {
            f[i] = 1;
            ++res;
        }
        sum += f[i];
        if (i - k + 1 >= 0) {
            sum -= f[i - k + 1];
        }
        // if (3 == k) {
        //     cout << f[i] << endl;
        // }
    }
    for (int i = n - k + 1; i < n; ++i) {
        // if (3 == k) {
        //     cout << i << ", " << facing[i] << ", " << sum << endl;
        // }
        if (1 == (facing[i] + sum & 1)) { return INF; }
        if (i - k + 1 >= 0) {
            sum -= f[i - k + 1];
        }
    }
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    int minOper = 0;
    int minK = 1;
    for (int i = 0; i < n; ++i) {
        char c;
        scanf(" %c", &c);
        if ('B' == c) {
            facing[i] = 1;
            ++minOper;
        }
        else {
            facing[i] = 0;
        }
    }
    for (int k = 2; k <= n; ++k) {
        int opers = getMinOper(k, n);
        // cout << k << ", " << opers << endl;
        if (opers < minOper) {
            minOper = opers;
            minK = k;
        }
    }
    cout << minK << " " << minOper << endl;
    return 0;
}