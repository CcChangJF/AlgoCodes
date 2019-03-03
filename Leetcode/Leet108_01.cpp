#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        map<pair<string, string>, int> maps;
        for (int i = 0; i < emails.size(); i = i + 1) {
            string local = "";
            string domain = "";
            int cnt = 0;
            while(cnt < emails[i].length() && '@' != emails[i][cnt]) {
                if ('.' == emails[i][cnt]) {
                    cnt = cnt + 1;
                    continue;
                }
                else if ('+' == emails[i][cnt]) {
                    break;
                }
                else {
                    local = local + emails[i][cnt];
                    cnt = cnt + 1;
                }
            }
            while (cnt < emails[i].length() && '@' != emails[i][cnt]) {
                cnt = cnt + 1;
            }
            domain = emails[i].substr(cnt + 1, emails[i].length());
            //cout << "l : " << local << ", domain: " << domain << endl;
            if (maps.end() == maps.find(make_pair(local, domain))) {
                maps[make_pair(local, domain)] = 1;
            }
        }
        return maps.size();
    }
};

int main() {
    Solution s;
    vector<string> test;
    test.push_back("test.email+alex@leetcode.com");
    test.push_back("test.e.mail+bob.cathy@leetcode.com");
    test.push_back("testemail+david@lee.tcode.com");
    cout << s.numUniqueEmails(test) << endl;
    return 0;
}