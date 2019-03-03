#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string line;
    bool start = true;
    while(getline(cin, line)) {
        for (int i = 0; i < line.length(); ++i) {
            if('\"' == line[i]) {
                line.erase(i, 1);
                if (start) {
                    line.insert(line.begin() + i, '`');
                    line.insert(line.begin() + i, '`');
                }
                else {
                    line.insert(line.begin() + i, '\'');
                    line.insert(line.begin() + i, '\'');
                }
                start = !start;
            }
        }
        cout << line << endl;
    }


    return 0;
}