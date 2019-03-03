
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
    TreeNode* generateTree(int cur, int left, int right) {
        if(left > cur || right < cur) {
            return NULL;
        }
        TreeNode *root = new TreeNode(cur);
        for (int i = left; i < cur; ++i) {
            root -> left = generateTrees(i, left, cur);
        }
        

    }

public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode *> res = vector<TreeNode *>();
        if (0 == n) { return res;}

        
    }
};

int main() {

    return 0;
}