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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (0 == matrix.size() || 0 == matrix[0].size()) {return false;}
        int cols = matrix[0].size();
        int start = 0;
        int end = matrix.size() - 1;
        while(start <= end) {
            int mid = start + (end - start) / 2;
            if(matrix[mid][cols - 1] == target) {
                return true;
            }
            else if (matrix[mid][cols - 1] < target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        if (start == matrix.size()) {return false;}
        int row = start;
        start = 0;
        end = matrix[0].size() - 1;
        while(start <= end) {
            int mid = start + (end - start) / 2;
            if (matrix[row][mid] == target) {
                return true;
            }
            else if (matrix[row][mid] < target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return false;
    }
};

int main() {
    Solution s;


    return 0;
}





