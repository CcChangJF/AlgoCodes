#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        set<string> set1;
        unordered_map<string, string> set2;
        unordered_map<string, string> set3;
        char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
        for (int i = 0; i < wordlist.size(); ++i) { 
            string ori = wordlist[i];
            string str = wordlist[i];
            set1.insert(str); 
            transform(str.begin(), str.end(), str.begin(), ::tolower);
            if (0 == set2.count(str)) {
                set2.insert(make_pair(str, ori));
            }
            for (int j = 0; j < str.length(); ++j) {
                for (int k = 0; k < 5; ++k) {
                    if (vowels[k] == str[j]) {
                        str[j] = '1';
                        break;
                    }
                }
            }
            if (0 == set3.count(str)) {
                set3.insert(make_pair(str, ori));
            }
        }
        vector<string> ans;
        for (int i = 0; i < queries.size(); ++i) {
            string ori = queries[i];
            string str = queries[i];
            if (0 != set1.count(ori)) {
                ans.push_back(ori);
                continue;
            }
            transform(str.begin(), str.end(), str.begin(), ::tolower);
            if (0 != set2.count(str)) {
                ans.push_back(set2[str]);
                continue;
            }
            for (int j = 0; j < str.length(); ++j) {
                for (int k = 0; k < 5; ++k) {
                    if (vowels[k] == str[j]) {
                        str[j] = '1';
                        break;
                    }
                }
            }
            if (0 != set3.count(str)) {
                ans.push_back(set3[str]);
                continue;
            }
            ans.push_back("");
        }
        return ans;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<string> wordlist = vector<string>({"KiTe","kite","hare","Hare"});
    vector<string> query = vector<string>({"kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"});

    Solution s;
    vector<string> ans = s.spellchecker(wordlist, query);
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << endl;
    }
    return 0;
}
