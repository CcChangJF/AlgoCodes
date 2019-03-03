
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cstdlib>
#include <ctime>
#include <string.h>

using namespace std;



int main() {
    int t;
    cin >> t;
    while (t--) {
        int num = 0;
        cin >> num;
        int cur = 6;
        int res = 0;
        while(0 != num && cur > 1) {
            res += num / cur;
            num = num % cur;
            --cur;
        }
        cout << res << endl;
    }

    return 0;
}