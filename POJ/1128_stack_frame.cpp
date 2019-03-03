
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>


using namespace std;

class Solution{
    void dfs(vector<string> &res, vector<vector<int> > &graph, 
        vector<int> &indegree, vector<bool> &mark, 
        vector<char> &cur, int v, int size) {
        cur.push_back(v + 'A');
        mark[v] = true;
        if (numberOfFrames == cur.size()) {
            res.push_back(string(cur.begin(), cur.end()));
        }
        else {
            for (int i = 0; i < size; ++i) {
                if (1 == graph[v][i]) {
                    --indegree[i];
                }
            }
            for (int i = 0; i < size; ++i) {
                if (!mark[i] && 0 == indegree[i]) {
                    // cout << i << endl;
                    dfs(res, graph, indegree, mark, cur, i, size);
                }
            }
            for (int i = 0; i < size; ++i) {
                if (1 == graph[v][i]) {
                    ++indegree[i];
                }
            }
        }
        mark[v] = false;
        cur.pop_back();
        return;
    }
public:
    int numberOfFrames;
    vector<string> stackFrame(vector<vector<char> > &board) {
        int rows = board.size();
        int cols = board[0].size();
        int size = 26;
        vector<vector<int> > corner(size, vector<int>(4 ,0));
        for (int i = 0; i < size; ++i) {
            corner[i][0] = INT_MAX;
            corner[i][1] = INT_MAX;
        }
        vector<bool> mark = vector<bool>(size, true);
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if ('.' != board[row][col]) {
                    int c = board[row][col] - 'A';
                    corner[c][0] = min(corner[c][0], row);
                    corner[c][1] = min(corner[c][1], col);
                    corner[c][2] = max(corner[c][2], row);
                    corner[c][3] = max(corner[c][3], col);
                    mark[c] = false;
                }
            }
        }

        // construct the graph
        vector<vector<int> > graph(size, vector<int>(size, 0));
        vector<int> indegree = vector<int>(size, 0);
        numberOfFrames = 0;
        for (int i = 0; i < size; ++i) {
            if (!mark[i]) {
                int firstRow = corner[i][0];
                int lastRow = corner[i][2];
                for (int col = corner[i][1]; col <= corner[i][3]; ++col) {
                    int c = board[firstRow][col] - 'A';
                    if (c != i && 0 == graph[i][c]) {
                        graph[i][c] = 1;
                        ++indegree[c];
                    }
                    c = board[lastRow][col] - 'A';
                    if (c != i && 0 == graph[i][c]) {
                        graph[i][c] = 1;
                        ++indegree[c];
                    }
                }
                int firstCol = corner[i][1];
                int lastCol = corner[i][3];
                for (int row = corner[i][0] + 1; row < corner[i][2]; ++row) {
                    int c = board[row][firstCol] - 'A';
                    if (c != i && 0 == graph[i][c]) {
                        graph[i][c] = 1;
                        ++indegree[c];
                    }
                    c = board[row][lastCol] - 'A';
                    if (c != i && 0 == graph[i][c]) {
                        graph[i][c] = 1;
                        ++indegree[c];
                    }
                }
                ++numberOfFrames;
            }
        }

        // for (int i = 0; i < size; ++i) {
        //     if (!mark[i]) {
        //         cout << char(i + 'A') << " : " << indegree[i] << endl;
        //     }
        // }

        // get stack
        vector<string> res = vector<string>();
        vector<char> cur = vector<char>();
        for (int i = 0; i < size; ++i) {
            if (!mark[i] && 0 == indegree[i]) {
                dfs(res, graph, indegree, mark, cur, i, size);
            }
        }
        // sort(res.begin(), res.end());
        return res;
    }
};

int main() {
    int h, w;
    Solution s;
    while (cin >> h >> w) {
        vector<vector<char> > board(h, vector<char>(w, '.'));
        for (int row = 0; row < h; ++row) {
            for (int col = 0; col < w; ++col) {
                cin >> board[row][col];
            }
        }
        vector<string> res = s.stackFrame(board);
        // cout << "size: " << res.size() << endl;
        for (int i = 0; i < res.size(); ++i) {
            cout << res[i] << endl;
        }

    }
    return 0;
}