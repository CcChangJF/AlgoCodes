
/*
(x,y) <- (3 - y, x)

(x,y) <- ( 3 - y, x)
(n - y, x) <- (n - x, n - y)


(x,y) <- (3 - y, x)
(n-x, n - y) <- (x, n - y)

(x,y) <- ()


*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
private:
    void rotateElem(vector<vector<int> > &matrix, int x, int y, int n) {
        int temp = matrix[x][y];
        matrix[x][y] = matrix[n - y][x];
        matrix[n - y][x] = matrix[n - x][n - y];
        matrix[n - x][n - y] = matrix[y][n - x];
        matrix[y][n - x] = temp;
        return;
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        if (0 == matrix.size() || 0 == matrix[0].size()) { return;}
        int size = matrix.size() - 1;
        for (int loop = 0; loop <= size / 2; ++loop) {
            for (int col = loop; col < size - loop; ++col) {
                rotateElem(matrix, loop, col, size);
            }
        }
        return;
    }
};

int main() {

    return 0;
}