
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

using namespace std;

typedef long long ll;
const int maxN = 200005;
ll nums[maxN];
ll res[maxN];

int main() {
    int n;
    memset(res, 0, sizeof(res));
    cin >> n;
    for (int i = 0; i < n / 2; ++i) {
        cin >> nums[i];
    }
    res[n - 1] = nums[0];
    res[0] = 0;
    for (int i = 1; i < n / 2; ++i) {
        res[i] = max(nums[i] - res[n - i], res[i - 1]);
        res[n - i - 1] = nums[i] - res[i];
    }
    for (int i = 0; i < n; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}