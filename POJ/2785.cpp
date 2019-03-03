
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

const int N = 4003;
int a[N];
int b[N];
int c[N];
int d[N];

const int MAXN = 1000003;
// int hashTable[MAXN];


int main() {
    int n;
    // cin >> n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        // cin >> a[i] >> b[i] >> c[i] >> d[i];
        scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
    }
    map<int, int> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ++m[0 - a[i] - b[j]];
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ans += m[c[i] + d[j]];
        }
    }
    cout << ans << endl;
    return 0;
}