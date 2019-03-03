// #define _USE_MATH_DEFINES
#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<int, long long> pil;
typedef std::pair<long long, long long> pll;

using namespace std;
const int INF = 0x3f3f3f3f;
#define PI 3.14159265358979323846

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    double r;
    cin >> n >> r;
    double ang = sin(2 * PI / n / 2);
    double ans = r * ang / (1.0 - ang);
    cout << fixed << setprecision(7) << ans << endl;


    return 0;
}