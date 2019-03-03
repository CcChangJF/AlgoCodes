#include <bits/stdc++.h>

typedef long long ll;

using namespace std;
int powers[32];
map<int, int> rev;
int res[32];

int getOnes(int n) {
    int ans = 0;
    while(0 != n) { 
        ++ans;
        n = n & n - 1;
    }
    return ans;
}

int highbit(int n) {
    int t = 1;
    while(0 != n) {
        t = n;
        n = n & n - 1;
    }
    return t;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    powers[0] = 1;
    for (int i = 1; i < 32; ++i) {
        powers[i] = (powers[i - 1] << 1);
        rev.insert(make_pair(powers[i], i));
    }
    int n, k;
    cin >> n >> k;
    // for (int n1 = 1; n1 <= 1000000000; ++n1) {
    //     for (int k1 = 1; k1 <= 200000; ++k1) {

    // int n1 = 277;
    // int k1 = 260;
    // n = n1;
    // k = k1;
    int test = 0;

    int ones = getOnes(n);

    if (n < k || ones > k) {
        cout << "NO" << endl;
    }
    else {
        for (int i = 1; i < ones; ++i) {
            int t = n & n - 1;
            if (t < k) { break;}
            ++res[rev[n - t]];
            n = t;
            --k;
        }
        while(0 != n) {
            // cout << n << " " << k << endl;
            if (0 == n % k && 1 == getOnes(n / k)) {
                res[rev[n / k]] += k;
                n = 0;
            } 
            else {
                int t = n / k;
                int cur = highbit(t);
                ++res[rev[cur]];
                n -= cur;
                --k;
            }
        }
        cout << "YES" << endl;
        for (int i = 0; i < 32; ++i) {
            // cout << res[i] << endl;
            for (int j = 0; j < res[i]; ++j) {
                cout << powers[i] << " ";
                // test += powers[i];
            }
        }
        cout << endl;
        memset(res, 0 ,sizeof(res));
        // cout << test << endl;
        // if (test != n1) {
        //     cout << "wrong: " << n1 << "," << k1 << endl;
        // }
    }
    //         }
    // }

    return 0;
}