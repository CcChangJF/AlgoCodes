
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

using namespace std;

const int N = 100005;
int nums[N];
double aux[N];
double sum[N];


int main() {
    int n,f;
    cin >> n >> f;
    double lower = INT_MAX;
    double upper = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> nums[i];
        if (nums[i] < lower) { lower = nums[i]; }
        if (nums[i] > upper) { upper = nums[i];}
    }
    while (upper - lower > 1e-5) {
        double mid = (upper + lower) / 2;
        for (int i = 1; i <= n; ++i) {
            aux[i] = nums[i] - mid;
        }
        for (int i = 1; i <= n; ++i) {
            sum[i] = sum[i - 1] + aux[i];
        }
        double minVal = 0;
        double ans = INT_MIN;
        for (int i = f; i <= n; ++i) {
            minVal = min(minVal, sum[i - f]);
            ans = max(ans, sum[i] - minVal);
        }
        // cout << mid << ", " << ans << endl;
        if (ans >= 0) {
            lower = mid;
        }
        else {
            upper = mid;
        }
    }
    cout << (int)(upper * 1000) << endl;

    return 0;
}