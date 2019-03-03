
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <iomanip>
#include <cmath>

using namespace std;

class Solution{
    double distance(int x1, int y1, int x2, int y2) {
        if (x1 == x2 && y1 == y2) {
            return INT_MAX;
        }
        double dx = x1 - x2;
        double dy = y1 - y2;
        return sqrt(dx * dx + dy * dy);
    }
public:
    double solve(vector<int> &x, vector<int> &y, int n) {
        vector<vector<double> > dis(n, vector<double>(n, INT_MAX));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dis[i][j] = distance(x[i], y[i], x[j], y[j]);
            }
        }
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    dis[i][j] = min(max(dis[i][k], dis[k][j]), dis[i][j]);
                }
            }
        }
        return dis[0][1];
    }
};

int main() {
    Solution s;
    int n;
    cin >> n;
    int count = 1;
    while (0 != n) {
        vector<int> x = vector<int>(n, 0);
        vector<int> y = vector<int>(n, 0);
        for (int i = 0; i < n; ++i) {
            cin >> x[i] >> y[i];
        }
        double res = s.solve(x, y, n);
        cout << "Scenario #" << count << endl;
        ++count;
        cout << "Frog Distance = " << std::fixed << setprecision(3) << res << endl;
        cout << endl;

        cin >> n;
    }
    return 0;
}