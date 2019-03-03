
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

const int maxN = 200001;
int counts[maxN];
int maxSal[maxN];
// int salaries[maxN][maxN];


int main() {
    int n;
    cin >> n;
    memset(counts, 0, sizeof(counts));
    memset(maxSal, 0, sizeof(maxSal));
    int pivot = 0;
    for (int i = 0; i < n; ++i) {
        cin >> counts[i];
        int sal = 0;
        for (int j = 0; j < counts[i]; ++j) {
            cin >> sal;
            maxSal[i] = max(maxSal[i], sal);
        }
        pivot = max(pivot, maxSal[i]);
    }
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        res = res + (long long)counts[i] * (pivot - maxSal[i]);
    }
    cout << res << endl;

    return 0;
}