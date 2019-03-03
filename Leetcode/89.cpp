
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res = vector<int>();
        if (n < 0) { return res;}
        res.push_back(0);
        if (0 == n) { return res;}
        res.push_back(1);
        if (1 == n) { return res;}
        for (int i = 1; i < n; ++i) {
            int base = (1 << i);
            for (int j = res.size() - 1; j >= 0; --j) {
                res.push_back(base + res[j]);
            }
        }
        return res;
    }
};

int main() {
    // n <= 0
    // n = 1
    // 
    return 0;
}