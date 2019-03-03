//Description



//TestCase
/*

*/

//Wrong case
/*

*/


/*
how to solve


*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long divide(vector<int> &A, int start, int end) {
        if (start >= end) {
            return 0;
        }
        else if (start == end - 1) {
            return A[start];
        }
        int min_value = A[start];
        int min_index = start;
        for(int index = start + 1; index < end; index = index + 1) {
            if (A[index] < min_value) {
                min_index = index;
                min_value = A[index];
            }
        }
        long long cur = (end - start) + (min_index - start) * (end - min_index - 1);
        cur = cur * min_value;
        return cur + divide(A, start, min_index) + divide(A, min_index + 1, end);
    }

    int sumSubarrayMins(vector<int>& A) {
        if (0 == A.size()) {return 0;}
        return (int)(divide(A, 0, A.size()) % 1000000007);
    }
};

int main() {
    Solution s;


    return 0;
}