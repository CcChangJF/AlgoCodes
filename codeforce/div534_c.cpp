#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<int, long long> pil;
typedef std::pair<long long, long long> pll;

using namespace std;
const int INF = 0x3f3f3f3f;

int deal(int s) {
    if ((s & 0xf000) == 0xf000) { s = s & 0x0fff;}
    if ((s & 0x0f00) == 0x0f00) { s = s & 0xf0ff; }
    if ((s & 0xf0) == 0xf0) { s = s & 0xff0f;}
    if ((s & 0xf) == 0xf) { s = s & 0xfff0; }

    if ((s & 0x8888) == 0x8888) { s = s & 0x7777; }
    if ((s & 0x4444) == 0x4444) { s = s & 0xbbbb; }
    if ((s & 0x2222) == 0x2222) { s = s & 0xdddd; }
    if ((s & 0x1111) == 0x1111) { s = s & 0xeeee; }
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string str;
    cin >> str;
    int s = 0;
    int n = str.length();
    for (int i = 0; i < n; ++i) {
        // cout << str[i] << endl;
        if ('0' == str[i]) {
            bool flag = false;
            for (int r = 0; r < 3; ++r) {
                for (int c = 0; c < 4; ++c) {
                    int num = (1 << r * 4 + c) | (1 << (r + 1) * 4 + c);
                    // cout << num << endl;
                    cout << (s | num) << endl;
                    if (0 == (s & num)) {
                        s = s | num;
                        cout << r + 1 << " " << c + 1 << endl;
                        flag = true;
                        break;
                    }
                }
                if (flag) { break; }
            }
            // cout << "before: " << s << endl;
            s = deal(s);
            // cout << "s: " << s << endl;
        }
        else {
            bool flag = false;
            for (int r = 0; r < 4; ++r) {
                for (int c = 0; c < 3; ++c) {
                    int num = (1 << (r * 4 + c)) | (1 << (r * 4 + c + 1));
                    cout << num << endl;
                    if (s & num == 0) {
                        s = s | num;
                        cout << r + 1 << " " << c + 1 << endl;
                        flag = true;
                        break;
                    }
                }
                if (flag) { break;}
            }
            s = deal(s);
        }
    }


    return 0;
}