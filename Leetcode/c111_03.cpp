
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> diStringMatch(string S) {
        vector<int> seq = vector<int>(S.length() + 1, 0);
        for (int i = 0; i < seq.size(); ++i) {
            seq[i] = i;
        }
        for (int i = 0; i < S.length(); ++i) {
            for (int j = i; j >= 0; --j) {
                if ('D' == S[j]) {
                    swap(seq[j + 1], seq[j]);
                }
                else if ('I' == S[j]) {
                    break;
                }
            }
        }
        return seq;
    }
};

int main() {
    Solution s;
    vector<int> res = s.diStringMatch("IDIDI");
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}