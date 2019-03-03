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
    int ans = -1;
    int start = 0;
    int end = n - 1;
    while(start < n && '[' != str[start]) { ++start; }
    if (start++ < n) { ans = 1; }
    else { ans = -1;}
    while(start < n && ':' != str[start]) { ++start; }
    if (start++ < n) { ++ans; }
    else { ans = -1;}

    while(end >= start && ']' != str[end]) { --end; }
    if (end-- >= start) { ++ans; }
    else { ans = -1;}
    while(end >= start && ':' != str[end]) { --end; }
    if (end-- >= start) { ++ans; }
    else { ans = -1;}

    for (int i = start; i <= end; ++i) {
        if ('|' == str[i]) { ++ans; }
    }
    cout << ans << endl;


    return 0;
}