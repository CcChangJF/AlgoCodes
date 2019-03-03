
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>


using namespace std;

int indices[15];
int bitVec[15];


void print_subset0(vector<int> &nums, int cur, int n) {
    for (int i = 0; i < cur; ++i) {
        cout << nums[indices[i]] << " ";
    }
    cout << endl;
    int s = (0 == cur) ? 0 : indices[cur - 1] + 1;
    for (int i = s; i < n; ++i) {
        indices[cur] = i;
        print_subset0(nums, cur + 1, n);
    }
    return;
}

void print_subset1(vector<int> &nums, int cur, int n) {
    if (cur == n) {
        for (int i = 0; i < n; ++i) {
            if (bitVec[i]) {
                cout << nums[i] << " ";
            }
        }
        cout << endl;
    }
    else {
        bitVec[cur] = 0;
        print_subset1(nums, cur + 1, n);
        bitVec[cur] = 1;
        print_subset1(nums, cur + 1, n);   
    }
    return;
}

// if n == 31, consider integer overflow
void print_subset2(vector<int> &nums, int n) {
    for (int i = 0; i < (1 << n); ++i) {
        for (int j = 0; j < n; ++j) {
            if (1 == ((i >> j) & 1)) {
                cout << nums[j] << " ";
            }
        }
        cout << endl;
    }
    return;
}


int main() {
    vector<int> nums = vector<int>({5,4,7});
    sort(nums.begin(), nums.end());
    memset(indices, 0, sizeof(indices));
    memset(bitVec, 0, sizeof(bitVec));
    print_subset1(nums, 0, nums.size());

    cout << endl;
    cout << "binary: " << endl;
    print_subset2(nums, nums.size());
    return 0;
}
