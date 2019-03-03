#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        sort(A.begin(), A.end());
        int mid = A.size() / 2 - 1;
        if (A[mid] == A[mid - 1]) {
            return A[mid];
        }
        else {
            return A[mid + 1];
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);



    return 0;
}