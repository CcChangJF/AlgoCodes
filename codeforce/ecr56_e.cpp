
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

const int maxN = 200005;
int numa[maxN];
int numb[maxN];
int hashTable[maxN];

void setZero(int start, int end) {
    for (int k = start; k <= end; ++k) {
        hashTable[numa[k]] = 0;
    }
    return;
}

void assignVal(int start, int end) {
    for (int k = start; k <= end; ++k) {
        hashTable[numa[k]] = 1;
    }
    return;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> numa[i];
        hashTable[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> numb[i];
    }
    int lastl = -1;
    int lastr = -2;
    for (int i = 0; i < m; ++i) {
        int type, la, ra, lb, rb;
        cin >> type;
        if (1 == type) {

            cin >> la >> ra >> lb >> rb;
            if (ra < lastl || lastr < la) {
                setZero(lastl, lastr);
                assignVal(la, ra);
            }
            else if (lastl <= la && lastr >= ra) {
                setZero(lastl, la - 1);
                setZero(ra + 1, lastr);
            }
            else if (la <= lastl && lastr <= ra) {
                assignVal(la, lastl - 1);
                assignVal(lastr + 1, ra);
            }
            else if (lastl < la && lastr < ra) {
                setZero(lastl, la - 1);
                assignVal(lastr + 1, ra);
            }
            else {
                setZero(ra + 1, lastr);
                assignVal(la, lastl - 1);
            }
            lastl = la;
            lastr = ra;
            // cout << "after: ";
            // for (int k = 1; k <= n; ++k) {
            //     cout << hashTable[numa[k]] << " ";
            // }
            // cout << endl;

            int cnt = 0;
            for (int k = lb; k <= rb; ++k) {
                if (1 == hashTable[numb[k]]) { ++cnt; }
            }
            cout << cnt << endl;
        }
        else {
            cin >> lb >> rb;
            swap(numb[lb], numb[rb]);
        }
    }
    return 0;
}