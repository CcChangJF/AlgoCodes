#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

// left, up, down, right
// bool flag = true;
const int MVs = 4;
int moveDir[4] = {-2, -1, 1, 2};
int moves[4][2] = {
    {0, -1},
    {-1, 0},
    {1, 0},
    {0, 1}
};

class Node {
public:
    vector<vector<int> > board;
    int n;
    int dis;
    int steps;
    int preNode;
    pair<int, int> zero;
    bool operator<(const Node &that) const {
        return dis + steps > that.dis + that.steps;
    }
    Node(vector<vector<int> > &b) {
        preNode = 0;
        n = b.size();
        board = vector<vector<int> >(b);
    }

    Node(const Node &b) {
        n = b.n;
        dis = b.dis;
        steps = b.steps;
        preNode = b.preNode;
        zero = b.zero;
        board = vector<vector<int> >(b.board);
    }

    void findZero() {
        bool find = false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (0 == board[i][j]) {
                    find = true;
                    zero.first = i;
                    zero.second = j;
                    break;
                }
            }
            if (find) { break; }
        }
        return;
    }

    void calDis(Node &that) {
        dis = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] != that.board[i][j]) { ++dis;}
            }
        }
        return;
    }
};

bool isLegalIndex(int row, int col, int n) {
    if (row < 0 || row >= n || col < 0 || col >= n) { return false; }
    return true;
}

bool bfs(priority_queue<Node> &p, Node &ori, Node &dest) {
    // if(flag) { cout << "p:" << endl; }
    // else { cout << "q: " << endl;}
    // flag = !flag;
    if (p.empty()) { return false; }
    Node cur = p.top();
    p.pop();

    // int n = cur.board.size();
    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < n; ++j) {
    //         cout << cur.board[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << cur.dis << ", top end. " << endl;


    int zeroRow = cur.zero.first;
    int zeroCol = cur.zero.second;
    for (int i = 0; i < MVs; ++i) {
        if (0 == cur.preNode + moveDir[i]) { continue; }
        Node t(cur);
        int zRow = zeroRow + moves[i][0];
        int zCol = zeroCol + moves[i][1];
        if (isLegalIndex(zRow, zCol, cur.board.size())) {
            t.zero = pair<int, int>(zRow, zCol);
            swap(t.board[zRow][zCol], t.board[zeroRow][zeroCol]);
            if (dest.board[zeroRow][zeroCol] == cur.board[zeroRow][zeroCol]) {
                ++t.dis;
            }
            if (dest.board[zRow][zCol] == cur.board[zRow][zCol]) {
                ++t.dis;
            }
            if (dest.board[zeroRow][zeroCol] == t.board[zeroRow][zeroCol]) {
                --t.dis;
            }
            if (dest.board[zRow][zCol] == t.board[zRow][zCol]) {
                --t.dis;
            }
            if (0 == t.dis) { return true; }
            t.steps = cur.steps + 1;
            t.preNode = moveDir[i];
            p.push(t);
            // for (int i = 0; i < n; ++i) {
            //     for (int j = 0; j < n; ++j) {
            //         cout << t.board[i][j] << " ";
            //     }
            //     cout << endl;
            // }
            // cout << t.dis << endl;
            // getchar();
        }
    }
    return false;
}

bool canReach(vector<vector<int> > &init,
    vector<vector<int> > &dest, int n) {
    priority_queue<Node> pOri;
    priority_queue<Node> pUpd;
    Node d = Node(dest);
    Node p = Node(init);
    p.calDis(d);
    p.steps = 0;
    p.findZero();
    pOri.push(p);


    int zeroRow = (p.zero.first + 1) % n;
    vector<vector<int> > changed(init);
    swap(changed[zeroRow][0], changed[zeroRow][1]);
    Node q = Node(changed);
    q.steps = 0;
    q.zero = p.zero;
    q.dis = p.dis;
    if (init[zeroRow][0] == dest[zeroRow][0]) { ++q.dis; }
    if (init[zeroRow][1] == dest[zeroRow][1]) { ++q.dis; }
    if (changed[zeroRow][0] == dest[zeroRow][0]) { --q.dis; }
    if (changed[zeroRow][1] == dest[zeroRow][1]) { --q.dis; }
    // printf("dis: %d, zero: %d, %d\n", q.dis, q.zero.first, q.zero.second);
    pUpd.push(q);
    while(!pOri.empty() || !pUpd.empty()) {
        if (bfs(pOri, p, d)) { return true; }
        if (bfs(pUpd, q, d)) { return false;}
    }
    return false;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // ifstream cin("in.txt");
    int n;
    while(cin >> n && 0 != n) {
        vector<vector<int> > init(n, vector<int>(n, 0));
        vector<vector<int> > dest(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> init[i][j];
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> dest[i][j];
            }
        }
        if (1 == n) {
            cout << "TAK" << endl;
            continue;
        }
        if (canReach(init, dest, n)) {
            cout << "TAK" << endl;
        }
        else {
            cout << "NIE" << endl;
        }
    }


    return 0;
}