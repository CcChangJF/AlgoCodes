
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>


using namespace std;



int main() {
    int n, r;
    cin >> n >> r;
    while (n--) {
        int R;
        cin >> R;
        if (R >= r) {
            cout << "Good boi" << endl;
        }
        else {
            cout << "Bad boi" << endl;
        }
    }
    return 0;
}