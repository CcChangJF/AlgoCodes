//Description



//TestCase
/*

*/

//Wrong case
/*
[4,2,0,3,2,5]

*/


/*
how to solve


*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        if (0 == heights.size()) {return 0;}
        heights.push_back(-1);
        stack<int> stk;
        int index = 0;
        int max_area = 0;
        while(index < heights.size()) {
            if (true == stk.empty() || heights[index] > heights[stk.top()]) {
                stk.push(index++);
            }
            else {
                int cur_height = heights[stk.top()];
                stk.pop();
                int width = (true == stk.empty()) ? index : (index - stk.top() - 1);
                max_area = max(max_area, cur_height * width);
            }
        }
        return max_area;
    }
};

class Solution1 {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (0 == heights.size()) {return 0;}
        heights.push_back(-1);
        stack<int> stk;
        stk.push(0);
        int max_area = heights[0];
        for(int i = 1; i < heights.size(); ++i) {
            if(heights[i] < heights[stk.top()]) {
                int max_height_index = stk.top();
                while(false == stk.empty() && heights[i] < heights[stk.top()]) {
                    max_height_index = stk.top();
                    stk.pop();
                    int width = (true == stk.empty()) ? i : (i - stk.top() - 1);
                    max_area = max(max_area, heights[max_height_index] * width);
                }
            }
            stk.push(i);
        }
        return max_area;
    }
};

int main() {
    Solution s;
    int d[] = {4,2,0,3,2,5};
    vector<int> test0(d, d + 6);
    cout << s.largestRectangleArea(test0) << endl;


    int a[] = {2,1,5,6,2,3};
    vector<int> test1(a, a + 6);
    cout << s.largestRectangleArea(test1) << endl;

    int b[] = {3,2,1,1,1};
    vector<int> test2(b, b + 5);
    cout << s.largestRectangleArea(test2) << endl;

    int c[] = {5,4,3,2,1};
    vector<int> test3(c, c + 5);
    cout << s.largestRectangleArea(test3) << endl;
    return 0;
}