
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > res = vector<vector<string> >();
        if (0 == strs.size()) { return res; }
      //  map<string, int> m = map<string, int>();
        map<string, int> m ;
        for (int i = 0; i < strs.size(); ++i) {
            string curStr = string(strs[i]);
            sort(curStr.begin(), curStr.end());
            if (m.end() == m.find(curStr)) {
                m.insert(make_pair(curStr, (int)res.size()));
                res.push_back(vector<string>({strs[i]}));
            }
            else {
                int index = m[curStr];
                res[index].push_back(strs[i]);
            }
        }
        return res;
    }
};

int main() {

    return 0;
}