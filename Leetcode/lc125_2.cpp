#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<int, long long> pil;
typedef std::pair<long long, long long> pll;

using namespace std;
const int INF = 0x3f3f3f3f;

class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int ans = 0;
        int rows = board.size();
        int cols = board[0].size();
        pair<int, int> rook;
        bool find = false;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if ('R' == board[row][col]) {
                    rook.first = row;
                    rook.second = col;
                    find = true;
                    break;
                }
            }
            if (find) { break;}
        }
        for (int row = rook.first + 1; row < rows; ++row) {
            if ('.' == board[row][rook.second]) { continue; }
            else {
                if(islower(board[row][rook.second])) { ++ans;}
                break;
            }
        }

        for (int row = rook.first - 1; row >= 0; --row) {
            if ('.' == board[row][rook.second]) { continue; }
            else {
                if(islower(board[row][rook.second])) { ++ans;}
                break;
            }
        }

        for (int col = rook.second + 1; col < cols; ++col) {
            if ('.' == board[rook.first][col]) { continue; }
            else {
                if(islower(board[rook.first][col])) { ++ans;}
                break;
            }
        }

        for (int col = rook.second - 1; col >= 0; --col) {
            if ('.' == board[rook.first][col]) { continue; }
            else {
                if(islower(board[rook.first][col])) { ++ans;}
                break;
            }
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);



    return 0;
}