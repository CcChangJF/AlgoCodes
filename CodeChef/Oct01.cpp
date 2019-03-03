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
    int solve(int p1, int p2, int k) {
        if ( 0 == (p1 + p2) / k % 2) {
            return 0;
        }
        else {
            return 1;
        }
    }
};

int main() {
    Solution s;

    int T=0;
    cin >> T;
    while(T--) {
        int p1=0, p2=0, k=0;
        cin >> p1 >> p2 >> k;
        int res = s.solve(p1, p2, k);
        if ( 0 == res) {
            cout << "CHEF" << endl;
        }
        else {
            cout << "COOK" << endl;
        }
    }

    return 0;
}