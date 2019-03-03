
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

using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
    void traversal(TreeNode *root, vector<int> &array, int num) {
        if (NULL == root) { return ;}
        ++cnt;
        if (num < 500) {
            array[num] = 1;
        }
        else {
            return;
        }
        traversal(root -> left, array, 2 * num);
        traversal(root -> right, array, 2 * num + 1);
        return;
    }

public:
    int cnt;
    bool isCompleteTree(TreeNode* root) {
        if (NULL == root) { return true;}
        vector<int> array = vector<int>(500, 0);
        cnt = 0;
        traversal(root, array, 1);
        for (int i = 1; i <= cnt; ++i) {
            if (0 == array[i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {

    return 0;
}