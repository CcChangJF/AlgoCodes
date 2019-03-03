
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution{
private:
    void swap(int &a, int &b) {
        int t = a;
        a = b;
        b = t;
        return;
    }

    void reverse(vector<int> &nums, int start, int end) {
        if (start >= end) {return;}
        else {
            int mid = (end - start) / 2;
            for (int i = 0; i <= mid; ++i) {
                swap(nums[start + i], nums[end - i]);
            }
            return;
        }
    }
public:
    void nextPermutation(vector<int>& nums) {

        if (nums.size() <= 1) {return;}
        int firstDec = -1;
        int swapPos = -1;
        for (int i = nums.size() - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]){ 
                firstDec = i;
                break;
            }
        }
        if (-1 == firstDec) {
            reverse(nums, 0, nums.size() - 1);
        }
        else {
            for (int i = nums.size() - 1; i > firstDec; --i) {
                if (nums[i] > nums[firstDec]) {
                    swapPos = i;
                    break;
                }
            }
            swap(nums[firstDec], nums[swapPos]);
            reverse(nums, firstDec + 1, nums.size() - 1);
        }
        return;
    }
};

int main() {
    Solution s;
    vector<int> rev = vector<int>({3,2,1});
    s.nextPermutation(rev);
    for (int i = 0; i < rev.size(); ++i) {
        cout << rev[i] << " ";
    } 
    cout << endl;
    vector<int> nums1 = vector<int>({1,2,2,4});
    vector<int> nums = vector<int>({1,2,2,4});
    do {
        cout << "nums : ";
        for (int i = 0; i < nums.size(); ++i) {
            cout << nums[i] << " ";
        }
        cout << endl;
        cout << "nums1: ";
        for (int i = 0; i < nums1.size(); ++i) {
            cout << nums1[i] << " ";
        }
        cout << endl;
        s.nextPermutation(nums1);
    } while(next_permutation(nums.begin(), nums.end()));

    return 0;
}