#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int t;
    int cache[32];
    cache[1] = 1;
    for (int i = 2; i < 32; ++i) {
        if (0 == i % 2) {
            cache[i] = cache[i-1] * 2 - 1;
        }
        else {
            cache[i] = cache[i-1] * 2 + 1;
        } 
    }
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int x = cache[n];
        int y = (1 << n);

        cout <<  x << " " <<  y << " ";
    }

    return 0;
}
