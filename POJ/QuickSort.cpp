
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

const int maxN = 100001;
int nums[maxN];
int n;

void quickSort(int start, int end) {
    if (start >= end - 1) { return; }
    int index = rand() % (end - start) + start;
    swap(nums[start], nums[index]);

    int pivot = nums[start];

    int first = start + 1;
    int last = end - 1;
    while (true) {
        while(first <= last && nums[first] <= pivot) { ++first;}
        while(last >= first && nums[last] > pivot) { --last;}
        if (first >= last) {break;}
        swap(nums[first++], nums[last--]);
    }

    swap(nums[start], nums[last]);
    quickSort(start, last);
    quickSort(last + 1, end);
    return;
}

int binarySearch(vector<int> &nums, int start, int end, int target) {
    while(start < end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] < target) {
            start = mid + 1;
        }
        else {
            end = mid;
        }
    }
    return start;
}

int main() {
    vector<int> test = vector<int>({2,3,3,5,6});
    return 0;
}