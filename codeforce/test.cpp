
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cstdlib>
#include <ctime>
#include <string.h>

using namespace std;

const int N = 100001;
int a[N];
int b[N];

int main() {
    priority_queue<int> p;
    int n = 10;
    for (int i = 0; i < n; ++i) {
        p.push(rand() % n);
    }

    while(!p.empty()) {
        cout << p.top() << "\t";
        p.pop();
    }
    cout << endl;

    return 0;
}