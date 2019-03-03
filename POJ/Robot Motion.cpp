
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>

using namespace std;

class Solution{
    int codeXY(int row, int col, int rows) {
        return row * rows + col;
    }

    bool isLegal(int row, int col, int rows, int cols) {
        if (row < 0 || col < 0 || row >= rows || col >= cols) {
            return false;
        }
        else {
            return true;
        }
    }

public: 
    int loopCount;
    int exitCount;
    void countSteps(vector<vector<char> > &board, int rows, int cols, int start) {
        loopCount = 0;
        exitCount = 0;
        map<int, int> m = map<int, int>();
        int step = 0;
        int curRow = 0;
        int curCol = start;
        while(isLegal(curRow, curCol, rows, cols) 
            && m.end() == m.find(codeXY(curRow, curCol, cols))) {
            ++step;
            // cout << curRow << " " <<  curCol << " " << codeXY(curRow, curCol, cols) << endl;
            m.insert(make_pair(codeXY(curRow, curCol, cols), step));
            switch (board[curRow][curCol]) {
                case 'N':
                    curRow = curRow - 1;
                    break;
                case 'S':
                    curRow = curRow + 1;
                    break;
                case 'W':
                    curCol = curCol - 1;
                    break;
                case 'E':
                    curCol = curCol + 1;
                    break;
            }
        }
        if (!isLegal(curRow, curCol, rows, cols)) {
            exitCount = step;
        }
        else {
            exitCount = m[codeXY(curRow, curCol, cols)] - 1;
            loopCount = step - exitCount;
        }
        return;
    }
};

int main() {
    Solution s;
    int rows;
    int cols;
    int start;
    cin >> rows >> cols >> start; 
    while (0 != rows && 0 != cols && 0 != start) {
        vector<vector<char> > board(rows, vector<char>(cols, '0'));
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                cin >> board[row][col];
            }
        }
        s.countSteps(board, rows, cols, start - 1);
        if (0 == s.loopCount) {
            cout << s.exitCount << " step(s) to exit" << endl;
        }
        else {
            cout << s.exitCount <<" step(s) before a loop of " << s.loopCount << " step(s)" << endl;
        }

        cin >> rows >> cols >> start;    
    }
    return 0;
}