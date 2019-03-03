
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
    string shortestSuperstring(vector<string>& A) {
        vector<vector<int> > end(A.size(), vector<int>(A.size(), 0));
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < A.size(); ++j) {
                for (int k = 0; k < A[i].size(); ++k) {
                    if (k <= A[j].size() && A[i][k] != A[j][k]) {
                        end[i][j] = k;
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < A.size(); ++i) {
            end[i][i] = 0;
        }
        //  for (int i = 0; i < A.size(); ++i) {
        //     for (int j = 0; j < A.size(); ++j) {
        //         cout << end[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        int start = 0;
        int maxEndLen = 0;
        vector<int> mark = vector<int>(A.size(), 0);
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < A.size(); ++j) {
                if (end[i][j] > maxEndLen) {
                    maxEndLen = end[i][j];
                    start = i;
                }
            }
        }
        //cout << start << endl;
        string res = A[start];
        cout << res << endl;
        for (int i = 0; i < A.size(); ++i) {
            if (start == i) {
                continue;
            }
            int maxIndex = 0;
            int maxLen = 0;
            for (int j = 0; j < A.size(); ++j) {
                if (end[start][j] > maxLen) {
                    maxLen = end[start][j];
                    maxIndex = j;
                }
            }
            res = res + A[start].substr(end[start][maxIndex], A[maxIndex].size() - end[start][maxIndex]);
            start = maxIndex;
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<string> s0 = vector<string>({"alex","loves","leetcode"});
    cout << s.shortestSuperstring(s0) << endl;

    vector<string> s1 = vector<string>({"catg","ctaagt","gcta","ttca","atgcatc"});
    cout << s.shortestSuperstring(s1) << endl;
    return 0;
}