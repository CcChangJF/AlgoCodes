#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<int, long long> pil;
typedef std::pair<long long, long long> pll;

using namespace std;
const int INF = 0x3f3f3f3f;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    if (0 == (n % 4)) { cout << 0 << endl;}
    else if (0 == n % 4 % 3) {
        cout << 0 << endl;
    }
    else {
        cout << 1 << endl;
    }


    return 0;
}