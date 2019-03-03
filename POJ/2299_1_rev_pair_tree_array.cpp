
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

struct Node{
    int val;
    int index;
    bool operator<(const Node &that) const {
        return val < that.val;
    }
};

const int N = 500005;
int nums[N];
int aux[N];
int arr[N + 1];
Node nums1[N];
int newNums[N];

int lowbit(int x) {
    return x & -x;
}

void addToTree(int k, int n) {
    while(k < n) {
        ++arr[k];
        k = k + lowbit(k);
    }
    return;
}

int getCount(int k) {
    int cnt = 0;
    while(k > 0) {
        cnt += arr[k];
        k = k - lowbit(k);
    }
    return cnt;
}


int main() {
    int n;
    while (cin >> n && 0 != n) {
        memset(arr, 0, sizeof(arr));
        for (int i = 0; i < n; ++i) {
            // nums[i] = rand() % N + 1;
            // nums[i] = n - i;
            cin >> nums[i];
            nums1[i].val = nums[i];
            nums1[i].index = i + 1;
        }
        // int ans1 = 0;
        // mergeSort(0, n, ans1);
        ll ans2 = 0;
        sort(nums1, nums1 + n);
        int p = 1;
        newNums[nums1[0].index] = p;
        for (int i = 1; i < n; ++i) {
            if (nums1[i].val == nums1[i - 1].val) {
                newNums[nums1[i].index] = p;
            }
            else {
                newNums[nums1[i].index] = ++p;
            }
        }
        // cout << "end" << endl;
        for (int i = 1; i <= n; ++i) {
            // cout << newNums[i] << "\t";
            addToTree(newNums[i], p + 1);
            // cout << nums1[i].val << " " << nums1[i].index << ", " << getCount(newNums[i]) << endl;
            ans2 += i - getCount(newNums[i]);
        }        
        cout << ans2 << endl;
    }

    // cout << ans1 << "\t" << ans2 << endl;
    return 0;
}