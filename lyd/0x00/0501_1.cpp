#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const int N = 100005;
int nums[N];

int partition(int start, int end) {
    if (start == end - 1) { return start;}
    int randIndex = rand() % (end - start) + start;
    swap(nums[randIndex], nums[start]);
    int pivot = nums[start];
    int begin = start + 1;
    int last = end - 1;
    while(begin <= last) {
        while(begin <= last && nums[begin] <= pivot) { ++begin; }
        while(begin <= last && nums[last] > pivot) { --last; }
        if (begin >= last) { break; }
        swap(nums[begin], nums[last]);
    }
    swap(nums[start], nums[last]);
    return last;
}

int getMedia(int n) {
    int k = (n - 1) / 2;
    int start = 0;
    int end = n;
    int cur = 0;
    while(true) {
        cur = partition(start, end);
        if (cur == k) { break; }
        else if (cur > k) {
            end = cur;
        }
        else {
            start = cur + 1;
        }
    }
    if (1 == (n & 1)) { return nums[k];}
    int minVal = INT_MAX;
    for (int i = k + 1; i < n; ++i) {
        if (nums[i] < minVal) { minVal = nums[i];}
    }
    return (int)((nums[k] + minVal) / 2.0 + 0.5);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    ll ans = 0;
    int median = getMedia(n);
    for (int i = 0; i < n; ++i) {
        ans += abs(nums[i] - median);
    }
    cout << ans << endl;

    return 0;
}