
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if (A.size() < 3) {
            return false;
        }
        int mountIndex = 1;
        while (mountIndex < A.size() && A[mountIndex] > A[mountIndex - 1]) {
            ++mountIndex;
        }
        if (1 == mountIndex || mountIndex == A.size()) { return false;}
        for (int i = mountIndex - 1; i < A.size() - 1; ++i) {
            if (A[i] <= A[i + 1]) {
                return false;
            }
        }
        return true;
    }
};

int main() {

    return 0;
}