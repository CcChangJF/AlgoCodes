#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<int, long long> pil;
typedef std::pair<long long, long long> pll;

using namespace std;
const int INF = 0x3f3f3f3f;

//<key, value, time>

class TimeMap {
    unordered_map<string, vector<pair<int, string> > > m;
    int binarySearch(vector<pair<int, string>> &v, int t) {
        int s = 0;
        int e = v.size();
        while(s < e) {
            int mid = (s + e) >> 1;
            if (v[mid].first < t) {
                s = mid + 1;
            }
            else {
                e = mid;
            }
        }
        return s;
    }
public:
    /** Initialize your data structure here. */
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        if (0 == m.count(key)) {
            m[key] = vector<pair<int, string> >();
            m[key].push_back(make_pair(timestamp, value));
        }
        else {
            int index = binarySearch(m[key], timestamp);
            if (index < m[key].size() && timestamp == m[key][index].first) {
                m[key][index].second = value;
            }
            else {
                m[key].insert(m[key].begin() + index, make_pair(timestamp, value));
            }
        }
        return;
    }
    
    string get(string key, int timestamp) {
        if (0 == m.count(key) || 0 == m[key].size()) {return ""; }
        else {
            int index = binarySearch(m[key], timestamp);
            // cout << "index: " << index << endl;
            if (0 == index && timestamp != m[key][index].first) { return ""; }
            if (index < m[key].size() && timestamp == m[key][index].first) {
                return m[key][index].second;
            }
            else {
                return m[key][index - 1].second;
            }

            // if (0 == index) { 
            //     if (timestamp != m[key][index].first) {
            //         return "";
            //     }
            //     else {
            //         return m[key][index].second;
            //     }
            // }
            // else {
            //     return m[key][index - 1].second;
            //     // if (index == m[key].size()) { return m[key][index - 1].second; }
            //     // else { return m[key][index].second;}
            // }
        }
    }

    // void print() {
    //     for (auto p : m) {
    //         cout << p.first << ": " << endl;
    //         for(int i = 0; i < m[p.first].size(); ++i) {
    //             cout << m[p.first][i].first << ", " << m[p.first][i].second << endl;
    //         }
    //     }
    // }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    TimeMap t;
    for (int i = 100; i > 10; --i) {
        string s = "";
        s.push_back(i / 26 + 'a');
        s.push_back(i % 26 + 'a');
        t.set("a", s, i);
    }
    t.print();


    // t.set("love","high",10);
    // t.set("love","low",20);
    // // t.print();
    // cout << t.get("love",5) << "\n";
    // cout << t.get("love",10) << "\n";
    // cout << t.get("love",15) << "\n";
    // cout << t.get("love",20) << "\n";
    // cout << t.get("love",25) << "\n";


    return 0;
}