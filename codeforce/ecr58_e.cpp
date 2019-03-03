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
    scanf("%d", &n);
    int minx = 0;
    int maxy = 0;
    for (int i = 0; i < n; ++i) {
        char c;
        int x, y;
        scanf(" %c %d %d", &c, &x, &y);
        if ('+' == c) {
            int t = min(x, y);
            minx = max(minx, t);
            t = max(x, y);
            maxy = max(maxy, t);
        }
        else {
            if (minx <= min(x, y) && maxy <= max(x, y)) {
                printf("YES\n");
            }
            else {
                printf("NO\n");
            }
        }
    }


    return 0;
}