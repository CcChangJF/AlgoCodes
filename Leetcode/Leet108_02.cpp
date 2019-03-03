#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int res = 0;
        if ( 0 == A.size()) { return 0;}
        int sum = 0;
        int cnt = 0;
        int start = 0;
        while(cnt < A.size()) {
            start = cnt;
            while(cnt < A.size() && sum < S) {
                sum = sum + A[cnt];
                cnt = cnt + 1;
            }
            while (cnt < A.size() && sum == S) {
                res = res + 1;
                sum = sum + A[cnt];
                cnt = cnt + 1;
            }
            if (cnt == A.size()) { 
                res = (sum == S) ? (res + 1) : res;
                break;
            }
            cnt = cnt - 1;
            start = start + 1;
            sum = sum - A[start];
            while(start < cnt && sum == S) {
                start = start + 1;
                res = res + 1;
                sum = sum - A[start];
            }
            



        } 
    }
};


int main() {

    return 0;
}