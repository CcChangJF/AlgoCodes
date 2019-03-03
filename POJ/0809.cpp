
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

const int maxN = 200001;
int n;
int nums[maxN];
int aux[maxN];
int res;

void mergeSort(int start, int end) {
    if (start >= end - 1) { return; }
    int mid = start + (end - start) / 2;
    mergeSort(start, mid);
    mergeSort(mid, end);
    for (int i = start; i < end; ++i) {
        aux[i] = nums[i];
    }
    int p = start;
    int q = mid;
    int index = start;
    while (p < mid || q < end) {
        if (q >= end || (p < mid && aux[p] <= aux[q])) {
            nums[index++] = aux[p++];
            // res = res + q - mid;
        }
        else {
            nums[index++] = aux[q++];
            // res = res + (mid - p);
        }
    }
    return;
}

int main() {
    while (cin >> n && 0 != n) {
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        res = 0;
        memset(aux, 0, sizeof(aux));
        mergeSort(0, n);
        cout << res << endl;
    }
    return 0;
}