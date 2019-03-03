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
    string str;
    cin >> str;
    int n = str.length();
    int ans = 0;
    stack<char> stk;
    stk.push(str[0]);
    for (int i = 1; i < n; ++i) {
        if (!stk.empty() && stk.top() == str[i]) {
            stk.pop();
            ++ans;
        }
        else {
            stk.push(str[i]);
        }
    }
    if (0 == (ans & 1)) { cout << "No" << endl;}
    else { cout << "Yes" << endl;}
    return 0;
}