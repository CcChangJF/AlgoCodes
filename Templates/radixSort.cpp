#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const int N = 100005;
int nums[N];
int counts[20];
int aux[N];
const int powers[10] = {1, 10, 100, 1000, 10000, 100000,1000000,10000000, 100000000, 1000000000};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n; 
        cin >> n;
        int maxVal = 0;
        for (int i = 0; i < n; ++i) {
            nums[i] = rand() % n + 10;
            if (nums[i] > maxVal) { maxVal = nums[i]; }
        }
        int len = 0;
        while (0 != maxVal) {
            ++len;
            maxVal /= 10;
        }
        int curIndex = 0;
        while(curIndex < len) {
            memset(counts, 0, sizeof(counts));
            for (int i = 0; i < n; ++i) {
                aux[i] = nums[i];
                ++counts[nums[i] / powers[curIndex] % 10 + 1];
            }
            
            for (int i = 1; i <= 10; ++i) {
                counts[i] += counts[i - 1];
            }

            for (int i = 0; i < n; ++i) {
                nums[counts[aux[i] / powers[curIndex] % 10]++] = aux[i];
            }
            ++curIndex;
      }
        for (int i = 0; i < n; ++i) {
            cout << nums[i] << "\t";
            if (0 == (i+1) % 5) { cout << endl; }
        }
        cout << endl;
    }



    return 0;
}