#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


bool isSuit(int year) {
    int rev = 0;
    int ori = year;
    while(0 != year) {
        rev = rev * 10 + year % 10;
        year /= 10;
    }
    if (rev - ori >= 1000) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a,b;
    cin >> a >> b;
    int cnt = 0;
    for (int i = a; i <= b; ++i) {
        if (isSuit(i)) { ++cnt; }
    }
    cout << cnt << endl;

    return 0;
}