
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
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_map<string, int> cnt;
    unordered_map<string, set<int> > exist;
    while (n--) {
        string name;
        cin >> name;
        int last = name.length() - 1;
        int count = 0;
        while(last >= 0 && '0' <= name[last] && name[last] <= '9') {
            count = count * 10 + name[last] - '0';
            if (count > 100000) {
                break;
            }
            --last;
        }
        string nameStr = name.substr(0, last + 1);

        if (0 == cnt.count(name)) {
            if (count > 100000 || 0 == count || 
                (last < name.length() - 1 && '0' == name[last + 1])) {
                if (0 == cnt.count(nameStr)) {
                    cout << name << endl;
                }
            }
            else {
                if (0 == cnt.count(nameStr) || cnt[nameStr] < count) {
                    set<int> cur = set<int>();
                    cur.insert(count);
                    exist[nameStr] = cur;
                }
                else {
                    int add = 1;
                    count = count * 10 + add;
                    while (0 != exist[nameStr].count(count) && count < cnt[nameStr]) {
                        ++add;
                        count = count + add;
                        

                    }
                }
            }
            ++cnt[name];
        }
        else {
            curCount = cnt[name];
            string extra = "";
            while (0 != curCount) {
                extra.insert(extra.begin(), curCount % 10 + '0');
                curCount /= 10;
            }
        }



        // ++cnt[name];
        if (count > 100000 || 0 == count || 
            (last < name.length() - 1 && '0' == name[last + 1])) {
            if (0 == cnt.count(name)) {
                cout << name;
            }
            else {
                cout << name;
                ++cnt[name];
                int curCount = cnt[name];
                string extra = "";
                while (0 != curCount) {
                    extra.insert(extra.begin(), curCount % 10 + '0');
                    curCount /= 10;
                }
                cout << extra;
            }
            cout << endl;
        }
        else {
            string nameStr = name.substr(0, last + 1);
            if (0 == cnt.count(nameStr)) {
                cout << name;
            }
        }



        string nameStr = name.substr(0, last + 1);
        if (0 == cnt.count(nameStr) || cnt[nameStr] < count) {
            cnt[nameStr] = 1;
            set<int> cur = set<int>();
            if (0 == exist.count(nameStr)) {
                cur.insert(count);
                exist[nameStr] = cur;
            }
            else {
                cur = exist[nameStr];
                cur.insert(count);
                exist[nameStr] = cur;
            }
            cout << name << endl;
        }
        else {
            int curNum = cnt[nameStr];
            while(0 != exist[nameStr].count(curNum)) {
                exist[nameStr].erase(curNum);
                ++curNum;
            }
            cnt[nameStr] = curNum + 1;
            string extra = "";
            while (0 != curNum) {
                extra.insert(extra.begin(), curNum % 10 + '0');
                curNum /= 10;
            }
            cout << nameStr << extra << endl;
        }
    }
    return 0;
}