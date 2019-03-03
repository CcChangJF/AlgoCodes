
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

const int N = 500005;
int nums[N];
int aux[N];
int n;

void mergeSort(int start, int end, ll &ans) {
    if (start >= end - 1) { return; }
    int mid = start + (end - start) / 2;
    mergeSort(start, mid, ans);
    mergeSort(mid,  end, ans);
    for (int i = start; i < end; ++i) {
        aux[i] = nums[i];
    }
    int p = start;
    int q = mid;
    int cnt = start;
    while (p < mid || q < end) {
        if (q >= end || (p < mid && aux[p] <= aux[q])) {
            nums[cnt++] = aux[p++];
            ans += q - mid;
        }
        else {
            nums[cnt++] = aux[q++];
        }
    }
    return;
}

int main() {
    // cout << INT_MAX << endl;
    // cout << (500001 * 500000) / 2 << endl;
    while (cin >> n && 0 != n) {
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }

        // for (int i = 0; i < n; ++i) {
        //     nums[i] = rand() % n;
        // }
        ll ans = 0;
        mergeSort(0, n, ans);
        cout << ans << endl;
    }

    return 0;
}