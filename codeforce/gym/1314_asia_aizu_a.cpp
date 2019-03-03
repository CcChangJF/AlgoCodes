#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int getOnes(int s) {
    int ans = 0;
    for (int i = s; 0 != i; i = (i & i - 1)) { ++ans; }
    return ans;
}

bool isEqual(int cur, int n, int k, int s) {
    if (k != getOnes(cur)) {return false; }
    else {
        int num = 0;
        for (int i = 0; i < n; ++i) {
            if ((cur & 1 << i) > 0) {
                num += i + 1;
            }
        }
        if (num == s) { return true;}
        return false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k,s;
    while(cin >> n >> k >> s, n != 0 || k != 0 || s != 0) {
        int ans = 0;
        int all = (1 << n);
        for (int i = 1; i < all; ++i) {
            if (isEqual(i,n,k,s)) {
                ++ans;
            }
        }
        cout << ans << endl;
    }

    return 0;
}