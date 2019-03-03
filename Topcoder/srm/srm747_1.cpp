#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<int, long long> pil;
typedef std::pair<long long, long long> pll;

using namespace std;
const int INF = 0x3f3f3f3f;

class MostFrequentLastDigit{
public:
    vector<int> generate(int n, int d) {
        vector<int> res = vector<int>(n, 0);
        if (0 == (d & 1)) {
            if (0 == d) { d = 10; }
            for (int i = 0; i < n; ++i) {
                res[i] = d / 2 + i * 10;
            }
        }
        else {
            if (1 == d) { d = 11; }
            for (int i = 0; i < n; i = i + 2) {
                res[i] = d / 2 + (i / 2) * 10;
                res[i + 1] = (d / 2 + 1) + (i / 2) * 10;
            }
            if (1 == (n & 1)) {
                res[n - 1] = d / 2 + n * 10;
            }
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    MostFrequentLastDigit s;
    s.generate(2,1);
    s.generate(4,7);
    s.generate(2,8);
    s.generate(7,2);

    return 0;
}