
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

class Point{
public:
    float cenX;
    int x, y;
    Point(int _x, int _y, int r) {
        x = _x;
        y = _y;
        cenX = sqrt((float)r * r - (float)y * y) + x;
    }
};

class Compare {
    public:
    bool operator()(Point &a, Point &b) {
        return a.cenX > b.cenX;
    }
};

bool check(int y, int r) {
    if (r < y) { return false; }
    else { return true; }
}

bool isWithinRange(Point &p, float x, int r) {
    float dx = p.x - x;
    if (r * r >= p.y * p.y + (dx * dx)) { return true; }
    else { return false;}
}

int main() {
    int n,r;
    int caseCnt = 1;
    while(cin >> n >> r, n != 0 && r != 0) {
        bool flag = true;
        priority_queue<Point, vector<Point>, Compare> pqs;
        for (int i = 0; i < n; ++i) {
            int x,y;
            cin >> x >> y;
            if (!check(y, r)) { flag = false; }
            if (flag) {
                pqs.push(Point(x, y, r));
            }
        }
        int ans = 0;
        if (!flag) { ans = -1; }
        else {
            while(!pqs.empty()) {
                ++ans;
                Point curP = pqs.top();
                float curX = curP.cenX;
                do {
                    pqs.pop();
                    curP = pqs.top();
                    // cout << curP.cenX << endl;
                } while(!pqs.empty() && isWithinRange(curP, curX, r));
            }
        }

        cout << "Case " << caseCnt++ << ": ";
        cout << ans << endl;
    }
    return 0;
}