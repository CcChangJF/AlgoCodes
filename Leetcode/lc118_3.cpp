#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<int, long long> pil;
typedef std::pair<long long, long long> pll;

using namespace std;
const int INF = 0x3f3f3f3f;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    bool getNum(TreeNode* root, int start, int end) {
        if (start == end) { return false; }
        int cur = start;
        if (root -> val != voy[cur]) { return false;}
        if (NULL == root -> left || NULL == root -> right) { 
            if (NULL != root -> left) { 
                return (start + 1 < voy.size() && getNum(root -> left, start + 1, end));
            }
            if (NULL != root -> right) {
                return (start + 1 < voy.size() && getNum(root -> right, start + 1, end)) ;
            }
            return true; 
        }
        if (cur + 1 >= end) { return false; }
        if (root -> left -> val != voy[cur + 1]) {
            TreeNode *t = root -> left;
            root -> left = root -> right;
            root -> right = t;
            ans.push_back(root -> val);
        }
        int index = cur + 1;
        while(index < voy.size() && voy[index] != root -> right -> val) { ++index; }
        if (index == voy.size()) { return false; }

        if (!getNum(root -> left, cur + 1, index) || 
            !getNum(root -> right, index, end)) { return false;}
        return true;
    } 
public:
    vector<int> ans;
    vector<int> voy;
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> error(1, -1);
        ans = vector<int>();
        voy = voyage;
        if (NULL == root) { return ans; }
        if (getNum(root, 0, voyage.size())) { return ans; }
        else { return error;}  
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);



    return 0;
}