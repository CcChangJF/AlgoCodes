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
    vector<int> sortArrayByParity(vector<int>& A) {
        if (0 == A.size()) {return vector<int>();}
        vector<int> res(A.begin(), A.end());
        int start = 0;
        int end = res.size() - 1;
        while(start < end) {
            while (start < res.size() && start < end && 0 == res[start] % 2) {
                start = start + 1;
            }
            while ( end >= 0 && start < end && 1 == res[end] % 2 ) {
                end = end - 1;
            }
            if ( start < end ) {
                swap(res[start], res[end]);
                start = start + 1;
                end = end - 1;
            }
        }
        return res;
    }
};


int main() {
    Solution s;


    return 0;
}