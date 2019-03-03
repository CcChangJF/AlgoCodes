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
const int maxN = 200005;


int r[maxN], sa[maxN], rnk[maxN], height[maxN];
int auxa[maxN], auxb[maxN], cnt[maxN];

void printsa(int n, string &str) {
    for (int i = 0; i < n; ++i) {
        for(int j = sa[i]; j < n; ++j) {
            cout << str[j];
        }
        cout << endl;
    }
    return;
}

void doubleAmpily(int n, int m) {
    memset(auxa, 0, sizeof(auxa));
    memset(auxb, 0, sizeof(auxb));
    memset(sa, 0, sizeof(sa));
    int i,j,p;
    int *x = auxa;
    int *y = auxb;
    for (i = 0; i < m; ++i) { cnt[i] = 0; }
    for (i = 0; i < n; ++i) { ++cnt[x[i] = r[i]]; }
    for (i = 1; i < m; ++i) { cnt[i] += cnt[i - 1]; }
    for (i = n - 1; i >= 0; --i) { sa[--cnt[x[i]]] = i; }

    for (p = 0, j = 1; p < n; j <<= 1) {
        for (i = n - j, p = 0; i < n; ++i) { y[p++] = i; }
        for (i = 0; i < n; ++i) {
            if (sa[i] >= j) { y[p++] = sa[i] - j; }
        }
        for (i = 0; i < m; ++i) { cnt[i] = 0; }
        for (i = 0; i < n; ++i) { ++cnt[x[y[i]]]; }
        for (i = 1; i < m; ++i) { cnt[i] += cnt[i - 1]; }
        for (i = n - 1; i >= 0; --i) { sa[--cnt[x[y[i]]]] = y[i]; }
        int *t = x; 
        x = y; y = t;
        for (x[sa[0]] = 0, i = 1, p = 1; i < n; ++i) {
            x[sa[i]] = (y[sa[i]] == y[sa[i - 1]] && 
                y[sa[i]+ j] == y[sa[i - 1] + j]) ? p - 1 : p++;
        }
        m = p;
    }
    return;
}

void calHeight(int n) {
    for (int i = 1; i <= n; ++i) { rnk[sa[i]] = i; }
    int k = 0;
    for (int i = 0; i < n; ++i) {
        if(k > 0) { --k; }
        int j = sa[rnk[i] - 1];
        while(r[i + k] == r[j + k]) { 
            ++k; 
        }
        height[rnk[i]] = k;
    }
    return;
}

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    string str = str1 + "#" + str2;
    int n = str.length();
    for (int i = 0; i < n; ++i) { 
        r[i] = str[i] - 'a' + 1;
    }
    r[str1.length()] = 27;
    r[n] = 0;

    // str = "abcdedg";
    // n = str.length();
    // for (int i = 0; i < n; ++i) {
    //     r[i] = str[i] - 'a' + 1;
    // }
    // r[n] = 0;
    doubleAmpily(n + 1, 28);
    // printsa(n, str);

    // cout << "da end" << endl;
    calHeight(n);
    // for (int i = 0; i < n; ++i) {
    //     cout << height[i] << " ";
    // }
    // cout << endl;
    int ans = 0;
    int k = str1.length();
    for (int i = 1; i <= n; ++i) {
        if (height[i] > ans && ll(sa[i - 1] - k) * (sa[i] - k) < 0) {
            ans = height[i];
        }
    }
    cout << ans << endl;
    return 0;
}