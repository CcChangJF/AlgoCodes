
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
#include <stdio.h>
#include <fstream>

using namespace std;
typedef long long ll;

ll bestPro;
ll n;
ll s1, v1, s2, v2;
void search(int maxVal, ll s, ll val, ll otherS, ll otherVal) {
    for (int i = 0; i <= maxVal; ++i) {
        if (i * s <= n) {
            ll pro = i * val + (n - i * s) / otherS * otherVal;
            //cout << i << " " << (n - i * s) / otherS << " " << pro << endl;
            if (bestPro < pro) {
                bestPro = pro;
            }
        }
        else {break;}
    }
    return;
}


int main() {
    // ifstream cin("in.txt");
    // ofstream cout("out.txt");


    int t;
    cin >> t;
    int cnt = 0;
    while(++cnt <= t) {
        cin >> n >> s1 >> v1 >> s2 >> v2;
        bestPro = 0;
        int enumV1 = n / s1;
        int enumV2 = n / s2;
        int enumV = (s1 * v2 > s2 * v1) ? s2 : s1;
        int minEnum = min(enumV1, enumV2);
        minEnum = min(minEnum, enumV);
        if (minEnum == enumV1) {
            search(minEnum, s1, v1, s2, v2);
        }
        else if (minEnum == enumV2) {
            search(minEnum, s2, v2, s1, v1);
        }
        else {
            if (s1 * v2 > s2 * v1) {
                search(minEnum, s1, v1, s2, v2);
            }
            else {
                search(minEnum, s2, v2, s1, v1);
            }
        }
        // printf("Case #%d: %lld\n", cnt, bestPro);

        cout << "Case #" << cnt << ": " << bestPro << endl;
    }
    return 0;
}