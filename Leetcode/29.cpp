//Description



//TestCase
/*

*/

//Wrong case
/*

*/


/*
how to solve
10 1010
3  0011

1010 - 0110 = 100

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        int flag = ((dividend > 0) ? 1 : -1 ) * ((divisor > 0) ? 1 : -1);
        long long res = 0;
        long long dend = labs(dividend);
        long long dsor = labs(divisor);
        if (dend < dsor) { return 0;}
        for (int offset = 31; offset >= 0; offset = offset - 1) {
            long long subtractor = dsor << offset;
            //cout << "sub: " << subtractor << ", divisor: " << divisor << endl;
            if ( subtractor >= dsor && subtractor <= dend) {
                dend -= subtractor;
                res += (long long)(1) << offset;
                // << "sub: " << subtractor << ", divisor: " << dsor << ", dend: " << dend <<  ", res: " << res << endl;                
            }
        }
        res = res * flag;
        if ( res >= 2147483647 ) { res = 2147483647;}
        return res;
    }
};

int main() {
    Solution s;
    cout << s.divide(-2147483648, -1) << endl;
    cout << s.divide(7, -3) << endl;
    cout << s.divide(10, 3) << endl;

    return 0;
}


