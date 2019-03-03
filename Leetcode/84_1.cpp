
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;


class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        if (0 == heights.size()) { return 0;}
        stack<int> stk = stack<int>();
        int maxArea = 0;
        heights.push_back(-1);
        for (int i = 0; i < heights.size(); ++i) {
            if (stk.empty() || heights[i] >= heights[stk.top()]) {
                stk.push(i);
            }
            else {
                while (!stk.empty() && heights[i] < heights[stk.top()]) {
                    int curHeight = heights[stk.top()];
                    stk.pop();
                    int width = (stk.empty()) ? i : (i - stk.top() - 1);
                    maxArea = max(maxArea, curHeight * width);
                }
                stk.push(i);
            }
        }
        return maxArea;
    }
};


class Solution1 {
public:
    int largestRectangleArea(vector<int> &heights) {
        if (0 == heights.size()) { return 0;}
        stack<int> stk = stack<int>();
        int maxArea = 0;
        heights.push_back(-1);
        int index = 0;
        while(index < heights.size()) {
            if (stk.empty() || heights[index] >= heights[stk.top()]) {
                stk.push(index++);
            }
            else {
                int curIndex = stk.top();
                stk.pop();
                int width = (true == stk.empty()) ? index : (index - stk.top() - 1);
                maxArea = max(maxArea, width * heights[curIndex]);
            }
        }
        return maxArea;
    }
};

int main() {
    Solution s;
    vector<int> test = vector<int>({2,1,1,2,3});
    cout << s.largestRectangleArea(test) << endl;

    return 0;
}