
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>


using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        
        return vector<int>();
    }
};

int main() {
    int ans = 0;
    for (int i = 2; i < 7; ++i) {
        ans = (ans + 2) % (i - 1);
    }
    cout << ans;
    return 0;
}