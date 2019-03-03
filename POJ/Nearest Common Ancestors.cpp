
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

class Solution{
public: 
    int commanAncestor(vector<int> &nums, int v1, int v2) {
        if (v1 == v2) { return v1;}
        stack<int> path1 = stack<int>();
        stack<int> path2 = stack<int>();
        while (v1 != nums[v1]) {
            path1.push(v1);
            v1 = nums[v1];
        }
        path1.push(v1);
        while(v2 != nums[v2]) {
            path2.push(v2);
            v2 = nums[v2];
        }
        path2.push(v2);
        int res = -1;
        while (!path1.empty() && !path2.empty()) {
            if (path1.top() == path2.top()) {
                res = path1.top();
                path1.pop();
                path2.pop();
            }
            else {
                break;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> tree = vector<int>(n + 1, 0);
        for (int i = 1; i < tree.size(); ++i) {
            tree[i] = i;
        }
        int par = 0;
        int child = 0;
        for (int i = 1; i < n; ++i) {
            cin >> par >> child;
            tree[child] = par;
        }
        int v1,v2;
        cin >> v1 >> v2;
        cout << s.commanAncestor(tree, v1, v2) << endl;
    }

    return 0;
}