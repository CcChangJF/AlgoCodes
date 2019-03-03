
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

class Solution{
    bool valid(int row, int col, int rows, int cols) {
        if (row < 0 || col < 0 || row >= rows || col >= cols) {
            return false;
        }
        else {
            return true;
        }
    }
    bool wins(vector<vector<int> > &board, vector<vector<int> > &mark,
     int row, int col, int rows, int cols) {
        int pivot = board[row][col];
        int index = 1;
        while (valid(row, col + index, rows, cols) 
            && 0 == (mark[row][col + index] & 1)
            && pivot == board[row][col + index]) {
            mark[row][col + index] = (1 | mark[row][col + index]);
            ++index;
        }
        if (5 == index) { return true;}
        index = 1;
        while (valid(row + index, col, rows, cols) 
            && 0 == (mark[row + index][col] & 2)
            && pivot == board[row + index][col]) {
            mark[row + index][col] = (2 | mark[row + index][col]);
            ++index;
        }
        if (5 == index) { return true;}
        index = 1;
        while (valid(row + index, col + index, rows, cols)  
            && 0 == (mark[row + index][col + index] & 4)
            && pivot == board[row + index][col + index]) {
            mark[row + index][col + index] = (4 | mark[row + index][col + index]);
            ++index;
        }
        if (5 == index) { return true;}
        index = 1;
        while (valid(row - index, col + index, rows, cols)  
            && 0 == (mark[row - index][col + index] & 8)
            && pivot == board[row - index][col + index]) {
            mark[row - index][col + index] = (8 | mark[row - index][col + index]);
            ++index;
        }
        if (5 == index) { return true;}
        else {
            return false;
        }
    }
public: 
    int winPlayer;
    int x;
    int y;
    Solution() {
        winPlayer = 0;
        x = 0;
        y = 0;
    }

    void solve(vector<vector<int> > &board, int rows, int cols) {
        winPlayer = 0;
        x = 0;
        y = 0;
        vector<vector<int> > mark(rows, vector<int>(cols, 0));
        for (int col = 0; col < cols; ++col) {
            for (int row = 0; row < rows; ++row) {
                if (0 != board[row][col]) {
                    if (15 != mark[row][col] && wins(board, mark, row, col, rows, cols)) {
                        winPlayer = board[row][col];
                        x = row + 1;
                        y = col + 1;
                        break;
                    }
                }
            }
        }
    }
};

int main() {

    Solution s;
    int T = 0;
    int rows = 19;
    int cols = 19;
    cin >> T;
    while(T--) {
        vector<vector<int> > board(rows, vector<int>(cols, 0));
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                cin >> board[row][col];
            }
        }
        s.solve(board, rows, cols);
        cout << s.winPlayer << endl;
        if (0 != s.winPlayer) {
            cout << s.x << " " << s.y << endl;
        }
    }

    return 0;
}