#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int y,b,r;
    cin >> y >> b >> r;
    int t = min(y, b - 1);
    t = min(t, r - 2);
    cout << (3 * t + 3) << endl;


    return 0;
}