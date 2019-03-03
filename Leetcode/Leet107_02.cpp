

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minFlipsMonoIncr(string S) {
        if (0 == S.length()) {return 0;}
        int len = S.length();
        vector<int> zeros(len + 1, 0);
        for(int index = 1; index <= len; ++index) {
            zeros[index] = ('0' == S[index - 1]) ? zeros[index - 1] + 1 : zeros[index - 1];
        }
        int ret = len - zeros[len];
        for(int index = 0; index <= len; ++index) {
            ret = min(ret, index - zeros[index] + zeros[len] - zeros[index]);
        }
        return ret;
    }
};

int main() {
    Solution s;
    cout << s.minFlipsMonoIncr("00110") << endl;
    cout << s.minFlipsMonoIncr("010110") << endl;
    cout << s.minFlipsMonoIncr("00011000") << endl;
    return 0;
}