//Description



//TestCase
/*

*/

//Wrong case
/*

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
    int binarySearch(vector<int> &nums, int target, int first, int last) {
        if (first > last || first >= nums.size()) {
            return -1;
        }
        int start = first;
        int end = last;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] < target) {
                start = mid + 1;
            }
            else if (nums[mid] > target) {
                end = mid - 1;
            }
            else {
                return mid;
            }
        }
        return -1;
    }
    int findReverseIndex(vector<int> &nums) {
        int start = 0;
        int end= nums.size() - 1;
        while(start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[start] < nums[mid]) {
                start = mid;
            }
            else {
                end = mid;
            }
            if (start == end || nums[start] > nums[start + 1]) {
                break;
            }
        }
        return start;
    }
    int search(vector<int>& nums, int target) {
        if (0 == nums.size()) {return -1;}
        int index = findReverseIndex(nums);
        if (target >= nums[0] && target <= nums[index]) {
            return binarySearch(nums,target, 0, index);
        }
        else {
            return binarySearch(nums, target, index + 1, nums.size() - 1);
        }
    }
};

int main() {

    return 0;
}