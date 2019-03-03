#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution1 {
public:
    int binarySearch(vector<int> &nums, int first, int last, int target) {
        int start = first;
        int end = last;
        while(start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] > target) {
                end = mid - 1;
            }
            else if (nums[mid] < target) {
                start = start + 1;
            }
            else {
                return mid;
            }
        }
        return -1;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        if(2 >= nums.size()) {return vector<vector<int> >();}
        vector<vector<int> > res = vector<vector<int> >();
        sort(nums.begin(), nums.end());
        for (int first = 0; first < nums.size() - 2; ++first) {
            if (0 != first && nums[first] == nums[first - 1]) {
                continue;
            }
            for (int sec = first + 1; sec < nums.size() - 1; ++sec) {
                if (sec == first + 1 || nums[sec] != nums[sec - 1]) {
                    int target = 0 - nums[first] - nums[sec];
                    if (-1 != binarySearch(nums, sec + 1, nums.size() - 1, target)) {
                        vector<int> cur = vector<int>(3,0);
                        cur[0] = nums[first];
                        cur[1] = nums[sec];
                        cur[2] = target;
                        res.push_back(cur);
                    }
                }
            }
        }
        return res;
    }
};

class Solution{
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(2 >= nums.size()) {return vector<vector<int> >();}
        vector<vector<int> > res = vector<vector<int> >();
        sort(nums.begin(), nums.end());
        for (int first = 0; first < nums.size() - 2; ++first) {
            if (0 != first && nums[first] == nums[first - 1]) {
                continue;
            }
            int start = first + 1;
            int end = nums.size() - 1;
            int target = 0 - nums[first];
            while (start < end) {
                if (first + 1 != start && nums[start] == nums[start - 1]) {
                    ++start;
                }
                else {
                    int sum = nums[start] + nums[end];
                    if ( sum > target) {
                        --end;
                    }
                    else if (sum < target) {
                        ++start;
                    }
                    else {
                        vector<int> cur = vector<int>(3);
                        cur[0] = nums[first];
                        cur[1] = nums[start++];
                        cur[2] = nums[end--];
                        res.push_back(cur);
                    }
                }
            }

        }
        return res;
    }
};


void print(vector<vector<int> > &res) {
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    Solution s;
    vector<int> c = vector<int>({-1, 0, 1, 2, -1, -4});
    vector<vector<int> > res = s.threeSum(c);
    print(res);

    return 0;
}