#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n,k;
        cin >> n >> k;
        for (int i = 0; i < n; ++i) {
            cout << (char)(i % k + 'a');
        }
        cout << endl;
    }


    return 0;
}