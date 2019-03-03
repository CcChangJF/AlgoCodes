#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const int N = 200005;
int nums[N];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int minFir = INT_MAX;
    int minSec = INT_MAX;
    int maxFir = INT_MIN;
    int maxSec = INT_MIN;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        if (nums[i] <= minSec) {
            minSec = nums[i];
        }
        if (minSec <= minFir) { swap(minSec, minFir); }
        if (nums[i] >= maxSec) { maxSec = nums[i];}
        if (maxSec >= maxFir) { swap(maxSec, maxFir);}
    }
    cout << min(maxFir - minSec, maxSec - minFir) << endl;


    return 0;
}