#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    // cin.tie(0);
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; ++i) {
        nums[i] = i + 1;
    }
    do {
        for (int i = 0; i < n; ++i) {
            cout << nums[i] << " ";
        }
        cout << endl;
    }while(next_permutation(nums.begin(), nums.end()));

    return 0;
}