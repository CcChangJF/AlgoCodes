
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
    string s;
    cin >> s;
    vector<int> powers = vector<int>({1, 10, 100, 1000, 10000, 100000,1000000});
    int index = 0;
    int cnt = 0;
    for (int i = s.length() - 2; s[i] != '['; --i) {
        index = (s[i] - '0') * powers[cnt++] + index;
    }
    cout << "index: " << index << endl;
    vector<vector<int> > vec;
    
    stack<int> s = stack<int>();
    string res = "";
    int cntIndex = 0;
    for (int i = 1; i < s.length() - cnt - 2; ++i) {
        if (index == cntIndex) {
            res.push_back(s[i]);

        }
        else {
            if (s.empty() && ',' == s[i]) {
                ++cntIndex;
            }
            else {
                

            }
        }
        
    }

    return 0;
}