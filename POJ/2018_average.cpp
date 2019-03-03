
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
#include <fstream>

typedef long long ll;

using namespace std;

const int N = 100005;
int nums[N];
int aux[N];
ll sum[N];
ll dp[N];

ll greaterThan(int aver, int n, int f) {
    aux[0] = nums[0] - aver;
    sum[0] = aux[0];
    dp[0] = 0;
    for (int i = 1; i < n; ++i) {
        aux[i] = nums[i] - aver;
        sum[i] = sum[i - 1] + aux[i];
        dp[i] = min(dp[i - 1], sum[i - 1]);
    }
    ll maxAver = sum[f - 1];
    for (int i = f; i < n; ++i) {
        maxAver = max(maxAver, sum[i] - dp[i - f + 1]);
    }
    // for (int i = 0; i < 100; ++i) {
    //     cout << sum[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < 100; ++i) {
    //     cout << dp[i] << " ";
    // }
    // cout << endl;
    return maxAver;
}

int main() {
    // ifstream cin("10.in");
    int n,f;
    cin >> n >> f;
    int lower = INT_MAX;
    int upper = 0;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        nums[i] = nums[i] * 1000;
        // cout << nums[i] << "\t";
        if (nums[i] < lower) { lower = nums[i];}
        if (nums[i] > upper) { upper = nums[i];}
    }
    // cout << endl;
    // cout << endl << lower << " " << upper << endl;
    // cout << nums[0] << " " << nums[n - 1] << endl;
    ++upper;
    while (lower < upper) {
        int mid = lower + (upper - lower) / 2;
        ll hasSol = greaterThan(mid, n, f);
        // getchar();
        // cout << "aver: " << mid << ", " << hasSol << endl;
        // if (0 == hasSol) {
        //     ans = mid;
        //     break;
        // }
        // else 
        if (hasSol >= 0) {
            lower = mid + 1;
        }
        else {
            upper = mid;
        }
    }
    cout << (--upper) << endl;
    return 0;
}