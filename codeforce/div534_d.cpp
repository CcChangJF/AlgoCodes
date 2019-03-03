#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<int, long long> pil;
typedef std::pair<long long, long long> pll;

using namespace std;
const int INF = 0x3f3f3f3f;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string str, res;
    while(cin >> str) {
        if ("end" == str || "mistake" == str || "e" == str) { break; }
        if ("start" == str) {
            int start = 1;
            int end = start * 2;
            while(true) {
                cout << "? " << start << " " << end << endl;
                fflush(stdout);
                cin >> res;
                if ("end" == res || "mistake" == res || "e" == res) { break; }
                if ("y" == res) { start *= 2; end *= 2; }
                else if ("x" == res) {
                    break;
                }
            }
            // end = ;
            if (1 == start) {
                cout << "? 2 3" << endl;
                fflush(stdout);
                cin >> res;
                if ("y" == res) { cout << "! 2" << endl; }
                else { cout << "! 1" << endl; }
                continue;
            }
            while(true) {
                int mid = (start + end) >> 1;
                cout << "? " << start << " " << mid << endl;
                fflush(stdout);
                cin >> res;
                if ("y" == res) { start = mid; }
                else if ("x" == res) { 
                    // if (start == mid) {
                    //     cout << "? " << mid << " " << end << endl;
                    //     fflush(stdout);
                    //     cin >> res;
                    //     if("x" == res) {cout << "! " << mid << endl;}
                    //     else { cout << "! " << end << endl; }
                    //     break;
                    // }
                    // else {
                        end = mid; 
                    // }
                }
                if (start >= end - 1) {
                    cout << "! " << end << endl;
                    fflush(stdout);
                    break;
                }
            }
        }
    }


    return 0;
}