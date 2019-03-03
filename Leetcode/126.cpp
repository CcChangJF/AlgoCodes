
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

class Solution {
    void getAns(vector<vector<string>> &res, vector<vector<int>> &edgeTo,
                vector<string> &cur, string begin, vector<string> &wordList, int v) {
        if (0 == v) {
            cur.insert(cur.begin(), begin);
            res.push_back(cur);
            cur.erase(cur.begin());
            return;
        }
        else {
            cur.insert(cur.begin(), wordList[v]);
            for (int i = 0; i < edgeTo[v].size(); ++i) {
                //cout << v << " " << edgeTo[v][i] << endl;
                getAns(res, edgeTo, cur, begin, wordList, edgeTo[v][i]);
            }
            cur.erase(cur.begin());
            return;
        }
    }
    
    int distance(string &a, string &b) {
        if (a.length() != b.length()) { return 0;}
        int cnt = 0;
        for (int i = 0; i < a.length(); ++i) {
            if (a[i] != b[i]) {
                ++cnt;
            }
        }
        return cnt;
    }
    
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string> > res;
        if (0 == wordList.size()) { return res;}
        int start = -1;
        int end = -1;
        int index = 0;
        while (index < wordList.size() && (-1 == start || -1 == end)) {
            if (wordList[index] == beginWord) {
                start = index;
            }
            else if (wordList[index] == endWord) {
                end = index;
            }
            ++index;
        }
        if (-1 == end) {
            return res;
        }
        else if (start == end) {
            res.push_back(vector<string>({wordList[start]}));
            return res;
        }
        vector<int> dis = vector<int>(wordList.size() + 1, INT_MAX);
        dis[0] = 1;
        vector<vector<int> > edgeTo(wordList.size() + 1, vector<int>());
        vector<bool> mark = vector<bool>(wordList.size() + 1);
        queue<int> q = queue<int>();
        q.push(0);
        wordList.insert(wordList.begin(), beginWord);
        mark[0] = true;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int i = 0; i < wordList.size(); ++i) {
                // string curWord = (0 == cur) ? beginWord : wordList[cur - 1];
                // if (1 == distance(curWord, wordList[i])) {
                //     // cout << i << endl;
                //     if (!mark[i + 1]) {
                //         mark[i + 1] = true;
                //         q.push(i + 1);
                //     }
                //     if (dis[i + 1] > dis[cur] + 1) {
                //         dis[i + 1] = dis[cur] + 1;wo
                //         edgeTo[i + 1] = vector<int>({cur});
                //     }
                //     else if (dis[i + 1] == dis[cur] + 1) {
                //         edgeTo[i + 1].push_back(cur);
                //     }
                // }
                if (1 == distance(wordList[cur], wordList[i])) {
                    if (!mark[i]) {
                        mark[i] = true;
                        q.push(i);
                    }
                    if (dis[i] > dis[cur] + 1) {
                        dis[i] = dis[cur] + 1;
                        edgeTo[i] = vector<int>({cur});
                    }
                    else if (dis[i] == dis[cur] + 1) {
                        edgeTo[i].push_back(cur);
                    }
                }
            }
        }
        // for (int i = 0; i < edgeTo.size(); ++i) {
        //     for (int j = 0; j < edgeTo[i].size(); ++j) {
        //         cout << edgeTo[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << 1 << endl;
        if (INT_MAX != dis[end + 1]) { 
            vector<string> cur;
            getAns(res, edgeTo, cur, beginWord, wordList, end + 1);
        }
        return res;
    }
};

int main() {
    vector<string> words = vector<string>({"hot","dot","dog","lot","log","cog"});
    Solution s;
    vector<vector<string> > res = s.findLadders("hit", "cog", words);

    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}