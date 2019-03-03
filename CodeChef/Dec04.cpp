
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

const int maxN = 20;
const int maxT = 19;
const int N = 150000;
int powers[maxN];

int main() {

    int n, c;
    int points = 1000;
    powers[0] = 1;
    for (int i = 1; i < maxN; ++i) {
        powers[i] = powers[i - 1] * 2; 
    }
    cin >> n >> c;
    int lower = 1;
    int upper = n + 1;
    bool beenBroken = false;
    while(points > 2 * c) {
        int curGuess = 0;
        // if (!beenBroken) {
        int times = (points + c) / (1 + c);
        curGuess = min(lower + max(powers[min(times, maxT) - 1] + 1, points - c), upper - 1);
        // }
        // else {
        //     curGuess = lower + (upper - lower) / 2;
        // }
        
        points -= 1;
        cout << "1 " << curGuess << endl;
        fflush(stdout);
        int isBroken = 0;
        cin >> isBroken;
        // cout << "isBroken: " << isBroken << endl;
        if (0 == isBroken) {
            lower = curGuess + 1;
        }
        else if (1 == isBroken) {
            cout << "2" << endl;
            beenBroken = true;
            upper = curGuess;
            points -= c;
        }
        if (lower >= upper) {
            cout << "3 " << upper << endl;
            break;
        }
    }
    if (lower != upper) {
        // while(true) {
        //     int guess = lower + (points - c);
        //     points -= 1;
        //     cout << "1 " << lower << endl;
        //     fflush(stdout);
        //     int isBroken;
        //     cin >> isBroken;
        //     if (1 == isBroken) {
        //         cout << "2" << endl;
        //         points -= c;
        //         upper = guess;
        //         break;
        //     }
        //     else {
        //         lower = guess + 1;
        //     }
        // }

        while(lower != upper && 0 != points) {
            points -= 1;
            cout << "1 " << lower << endl;
            fflush(stdout);
            int isBroken;
            cin >> isBroken;
            if (1 == isBroken) {
                break;
            }
            ++lower;
        }
        cout << "3 " << lower << endl;        
    }

    return 0;
}