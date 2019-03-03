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
    void getMatrix(vector<vector<int> > &res, int n, int loop, int& start_num){
        //up line
        for(int col = loop; col < n - loop; ++col){
            res[loop][col] = start_num++;
        }

        //right vector 
        for(int row = loop + 1; row < n - loop; ++row) {
            res[row][n - loop - 1] = start_num++;
        }

        //bottom line
        if(loop == n - loop - 1) {return;}
        for(int col = n - loop - 2; col >= loop; --col) {
            res[n - loop - 1][col] = start_num++;
        }

        //left vector
        if(loop == n - loop - 1) {return;}
        for(int row = n - loop - 2; row > loop; --row) {
            res[row][loop] = start_num++;
        }
        return;
    }

    vector<vector<int>> generateMatrix(int n) {
        if (0 == n) { return  vector<vector<int> >();}
        vector<vector<int> > res(n, vector<int>(n, 0));
        int start = 1;
        for(int loop = 0; loop <= (n - 1) / 2; ++loop) {
            getMatrix(res, n, loop, start);
        }
        return res;
    }
};

void print_vec(vector<vector<int> > &res) {
    for(int row = 0; row < res.size(); ++row) {
        for(int col = 0; col < res[row].size(); ++col) {
            cout << res[row][col] << " ";
        }
        cout << endl;
    }
}

int main() {
    Solution s;
    vector<vector<int> > res;
    res = s.generateMatrix(3);
    print_vec(res);

    res = s.generateMatrix(4);
    print_vec(res);

    return 0;
}