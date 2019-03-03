#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<int, long long> pil;
typedef std::pair<long long, long long> pll;

using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

void ext_gcd(int a,int b,int &d,int &x,int &y){
    if (b==0){
        d=a;x=1;y=0;
        return;
    }
    ext_gcd(b,a%b,d,y,x);
    y-=a/b*x;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    double a = 15 / 8;
    cout << a % MOD << endl;


    return 0;
}