// find the median of the two sorted array
// Furthur: find the kth num of the two sorted array

/* Wrong case:
[1,1,1,1,1] [1,2,3,4,5]
[1,1,2,2] [10]
[0] [0]
[1,1] [8,9]
[2] [4,6,7,8]

[1,3,5,7,9]
[5,5,5,5]

//// empty case.[] [1]

if array1_pivot == 0
    1. the [0] can be used, since 
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // [lo,hi)
    int binarySearch(vector<int> &nums, int lo, int hi, int target) {
        int start = lo;
        int end = hi - 1;
        while(start <= end) {
            int mid = start + (end - start) / 2;
            if (target <= nums[mid]) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        return start;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        bool odd = ((len1 + len2) % 2 == 1) ? true : false;
        if (0 == len1) {
            return (true == odd) ? nums2[(len2 - 1) / 2] : 
                (nums2[(len2 - 1)/2] + nums2[(len2 - 1)/2 + 1]) / 2.0;
        }
        if (0 == len2) {
            return (true == odd) ? nums1[(len1 - 1) / 2] : 
                (nums1[(len1 - 1)/2] + nums1[(len1 - 1)/2 + 1]) / 2.0;
        }
        int start_index = (len1 + len2 - 1) / 2;

        int start = 0;
        int end = len1 - 1;
        int index_array2 = 0;
        int index_array1 = 0;
        while (start <= end) {
            index_array1 = start + (end - start) / 2;
            index_array2 = binarySearch(nums2, 0, len2, nums1[index_array1]);
            if (index_array1 + index_array2 < (len1 + len2 - 1) / 2) {
                start = index_array1 + 1;
            }
            else if (index_array1 + index_array2 > (len1 + len2 - 1) / 2) {
                end = index_array1 - 1;
            }
            else {
                end = index_array1;
                break;
            }
        }
        
        double ret = 0;
        //cout << "start: " << start << ", end: " << end << endl;
        index_array2 = binarySearch(nums2, 0, len2, nums1[end]);
        if (start <= end) {
            //cout << "1: " << index_array1 << ", 2: "<< index_array2 << endl;
            ret = nums1[index_array1];
            if(false == odd){
                if (index_array2 > len2 - 1) {
                    ret = ret + nums1[index_array1 + 1];
                }
                else if (index_array1 == len1 - 1) {
                    ret = ret + nums2[index_array2];
                }
                else {
                    ret = ret + min(nums2[index_array2], nums1[index_array1 + 1]);
                } 
                ret = ret / 2;
            }

        }
        else {
            index_array1 = end;
            index_array2 = start_index - index_array1 - 1;
            ret = nums2[index_array2];
            if (false == odd) {
                if (index_array2 < len2 - 1) {
                    if (index_array1 < len1 - 1) {
                        ret = ret + min(nums2[index_array2 + 1], nums1[index_array1 + 1]);
                    }
                    else {
                        ret = ret + nums2[index_array2 + 1];
                    }
                }
                else {
                    ret = ret + nums1[index_array1 + 1];
                }
                ret = ret / 2;
            }
        }
        return ret;        
    }
};

int main() {
    Solution s;
    vector<int> nums1;
    vector<int> nums2;


    int test9[] = {3};
    int test10[] = {1,2,4};
    nums1 = vector<int>(test9, test9 + 1);
    nums2 = vector<int>(test10, test10 + 3);
    cout << s.findMedianSortedArrays(nums1, nums2) << endl;

/*
    int test13[] = {12};
    int test14[] = {8,9};
    nums1 = vector<int>(test13, test13 + 1);
    nums2 = vector<int>(test14, test14 + 2);
    cout << s.findMedianSortedArrays(nums1, nums2) << endl;

    int test1[1] = {4};
    int test2[1] = {4};
    nums1 = vector<int>(test1, test1 + 1);
    nums2 = vector<int>(test2, test2 + 1);
    cout << s.findMedianSortedArrays(nums1, nums2) << endl;


    int test3[] = {1,2};
    int test4[] = {1,2};
    nums1 = vector<int>(test3, test3 + 2);
    nums2 = vector<int>(test4, test4 + 2);
    cout << s.findMedianSortedArrays(nums1, nums2) << endl;

    int test15[] = {8,9};
    int test16[] = {1,1};
    nums1 = vector<int>(test15, test15 + 2);
    nums2 = vector<int>(test16, test16 + 2);
    cout << s.findMedianSortedArrays(nums1, nums2) << endl;


    int test5[] = {1,3,5,7,9};
    int test6[] = {5,5,5,5};
    nums1 = vector<int>(test5, test5 + 5);
    nums2 = vector<int>(test6, test6 + 4);
    cout << s.findMedianSortedArrays(nums1, nums2) << endl;

    int test7[] = {1,5,10};
    int test8[] = {8};
    nums1 = vector<int>(test7, test7 + 3);
    nums2 = vector<int>(test8, test8 + 1);
    cout << s.findMedianSortedArrays(nums1, nums2) << endl;



    int test11[] = {1,3,5,7,9};
    int test12[] = {2,4,6,8,10};
    nums1 = vector<int>(test11, test11 + 5);
    nums2 = vector<int>(test12, test12 + 5);
    cout << s.findMedianSortedArrays(nums1, nums2) << endl;
*/
    return 0;
}