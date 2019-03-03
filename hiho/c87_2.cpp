
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
#include <cmath>
// #include <climits>
#include <cfloat>
#include <iomanip>

using namespace std;

double calDis(int x, int y, int x0, int y0, int r) {
    double dx = x - x0;
    double dy = y - y0;
    return max(sqrt(dx * dx + dy * dy) - r, 0.0);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x1,y1,x2,y2;
        int x3,y3,r;
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> x3 >> y3 >> r;
        double ans = 0;
        double ver = DBL_MAX;
        double hor = DBL_MAX;
        double polar = DBL_MAX;
        if (x1 <= x3 && x3 <= x2 && y1 <= y3 && y3 <= y2) {
            ver = 0;
            hor = 0;
        }
        else if (x1 <= x3 && x3 <= x2) {
            ver = max(min(abs(y3 - y1), abs(y3 - y2)) - r, 0);
        }
        else if (y1 <= y3 && y3 <= y2) {
            hor = max(min(abs(x3 - x1), abs(x3 - x2)) - r, 0);
        }
        else {
            polar = min(calDis(x1, y1, x3, y3, r), calDis(x1, y2, x3, y3, r));
            double tmp = min(calDis(x2, y1, x3, y3, r), calDis(x2, y2, x3, y3, r));
            polar = min(polar, tmp);
        }
        ans = min(ver, hor);
        ans = min(ans, polar);
        cout << std::fixed << setprecision(6) << ans << endl;
    }

    return 0;
}