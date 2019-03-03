//Description



//TestCase
/*

*/

//Wrong case
/*
1,3,1,1,1
3

2,2,2,0,2,2
how to know the same number belong to the front part or the latter part.

*/


/*
how to solve

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findRevertIndex(vector<int> &nums) {
        int start = 0;
        int end = nums.size() - 1;
        while(start < end) {
            int mid = start + (end - start) / 2;
            if (mid != start && nums[mid] >= nums[start]) {
                start = mid;
            }
            else {
                end = mid;
            }
        }
        return start;
    }

    bool binarySearch(vector<int> &nums, int target, int begin, int end) {
        if( 0 == nums.size()) {return false;}
        while(begin <= end) {
            int mid = begin + (end - begin) / 2;
            if (nums[mid] == target) {
                return true;
            }
            else if (nums[mid] > target) {
                end = mid - 1;
            }
            else {
                begin = mid + 1;
            }
        }
        return false;
    }

    bool search(vector<int>& nums, int target) {
        if (0 == nums.size()) {return false;}
        int len = nums.size() - 1;
        int pivot = 0;
        if (nums[len] > nums[0]) {
            return binarySearch(nums, target, 0, len);
        }
        else if (nums[len] == nums[0]) {
            for(int i = 1; i <= len; ++i) {
                if (nums[i] >= nums[i - 1]) {
                    continue;
                }
                else {
                    pivot = i - 1;
                    break;
                }

            }
        }
        else {
            pivot = findRevertIndex(nums);
        }

        if(target == nums[0]) {
            return true;
        }
        else if (target < nums[0]) {
            return binarySearch(nums, target, pivot + 1, len);
        }
        else {
            return binarySearch(nums, target, 0, pivot);
        }
        
    }
};

int main() {
    Solution s;
    int a[] = {2,2,2,0,2,2};
    vector<int> test1(a, a + 6);
    cout << s.search(test1, 0) << endl;


    return 0;
}