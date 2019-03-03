#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

class Solution{
public:
    bool goodChef0(vector<int> &nums) {
        map<int, set<int> > m = map<int, set<int> >();
        for (int i = 1; i < nums.size(); ++i) {
            set<int> s = set<int>();
            if (m.end() != m.find(nums[i])) {
                s = m[nums[i]];
            }
            s.insert(i);
            m[nums[i]] = s;
        }
        for (map<int, set<int> >::iterator it = m.begin();
                it != m.end(); ++it) {
            set<int> index = it->second;
            if (1 < index.size()) {
                cout << it->first << endl;
                int cnt = 0;
                for (set<int>::iterator setIt = index.begin();
                        setIt != index.end(); ++setIt) {
                    if (m.end() != m.find(*setIt)) {
                        ++cnt;
                        if (cnt >= 2) {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }

    bool goodChef(vector<int> &nums) {
        set<int> index = set<int>();
        set<int> values = set<int>();
        for (int i = 1; i < nums.size(); ++i) {
            if (0 <= nums[i] && nums[i] < nums.size() && 
                index.end() == index.find(nums[i])) {
                index.insert(nums[i]);
                if (values.end() != values.find(nums[nums[i]])) {
                    return true;
                }
                values.insert(nums[nums[i]]);
            }
        }
        return false;
    }
};

int main() {
    int t;
    cin >> t;
    Solution s;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums = vector<int>(n + 1);
        int cnt = 0;
        while(cnt++ < n) {
            cin >> nums[cnt];
        }
        if (true == s.goodChef(nums)) {
            cout << "Truly Happy" << endl;
        }
        else {
            cout << "Poor Chef" << endl;
        }

    }
 

    return 0;
}
