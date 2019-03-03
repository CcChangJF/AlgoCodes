
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>


using namespace std;



int main() {
    int i = 1;
    for (int k = 31; k >= 0; --k) {
        cout << (i << k) << ", ";
    }
    int ask[31] = {1073741824, 536870912, 268435456, 134217728, 67108864, 
        33554432, 16777216, 8388608, 4194304, 2097152, 1048576, 524288, 
        262144, 131072, 65536, 32768, 16384, 8192, 4096, 2048, 1024, 512, 
        256, 128, 64, 32, 16, 8, 4, 2, 1};
    vector<int> a(31, 0);
    vector<int> b(31, 0);
    int count = 30;
    while (count >= 0) {
        cout << "? 0 0" << endl;
        fflush(stdout);
        int res;
        cin >> res;
        int cura = 

        /*

if (a[31] = b[31] ) {
    if (1)
        if (1) {
            0x0 0x1
            a[31] = 0
        }
        if (-1) {
            a[31] = 1
        }
    if (-1) { //a > b
        if (1) {
            a[31] = 1
        }
        if (-1) {
            a[31] = 0
        }
    }
}


*/
    }
    return 0;
}