
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

const int maxN = 50005;
int nums[maxN];
int vals[maxN];
int n;

int main() {
    int t; 
    // n = 20;
    // //0 3 2 3 2 7 
    // //0 3 2 5 4 5 5
    // //0 3 2 5 4 15 14 9
    // for (int i = 1; i < n; ++i) {
    //     if (i == n - 1) {
    //         if (1 == ((n - 1) & 1)) {
    //             cout << ((n - 1) ^ 1 ^ 3);
    //         }
    //         else {
    //             cout << ((n - 1) ^ 3 ^ 2);
    //         }
    //         continue;
    //     }
    //     int sec = (i + 1 >= n ) ? (i + 1 - n + 1) : (i + 1);
    //     int third = (i + 2 >= n ) ? (i + 2 - n + 1) : (i + 2);
    //     int forth = (i + 3 >= n ) ? (i + 3 - n + 1) : (i + 3);
    //     // cout << sec << " " << third << " " << forth << endl;
    //     if (1 == (i & 1)) {
    //         cout << (i ^ sec ^ third) << " ";
    //     }
    //     else {
    //         cout << (i ^ third ^ forth) << " ";
    //     }
    // }
    // cout << endl;    

    cin >> t;
     while(t--) {
        cin >> n;
        ++n;
        for (int i = 1; i < n; ++i) {
            // cout << i << " " << (i & 1) << endl;
            cout << "1 ";
            int sec = (i + 1 >= n ) ? (i + 1 - n + 1) : (i + 1);
            int third = (i + 2 >= n ) ? (i + 2 - n + 1) : (i + 2);
            int forth = (i + 3 >= n ) ? (i + 3 - n + 1) : (i + 3);  
            if (n - 1 == i) {
                if (1 == (i & 1)) {
                    cout << i << " 1 3" << endl;
                }
                else {
                    cout << i << " 2 3" << endl;
                }
            }
            else {
                if (1 == (i & 1)) {
                    cout << i << " " << sec << " " << third << endl;
                }
                else {
                    cout << i << " " << third << " " << forth << endl;
                }    
            }
            fflush(stdout);
            cin >> nums[i];
        }
        // cout << "nums: ";
        // for (int i = 0; i < n; ++i) {
        //     cout << nums[i] << " ";
        // }
        // cout << endl;

        for (int i = 1; i < n - 3; i = i + 2) {
            vals[i] = nums[i] ^ nums[i + 1] ^ nums[i + 2];
            // cout << i << ": " << vals[i] << endl;
        }
        for (int i = 2; i < n - 4; i = i + 2) {
            vals[i] = nums[i - 1] ^ vals[i - 1] ^ vals[i + 1];
        }
        if (1 == ((n - 1) & 1)) {
            vals[n - 1] = nums[n - 1] ^ vals[1] ^ vals[3];
            vals[n - 2] = nums[n - 2] ^ vals[1] ^ vals[2];
            vals[n - 3] = nums[n - 3] ^ vals[n - 2] ^ vals[n - 1];
            vals[n - 4] = nums[n - 5] ^ vals[n - 5] ^ vals[n - 3];
        }
        else {
            vals[n - 1] = nums[n - 1] ^ vals[2] ^ vals[3];
            vals[n - 2] = nums[n - 2] ^ vals[n - 1] ^ vals[1];
            vals[n - 3] = nums[n - 3] ^ vals[n - 1] ^ vals[1];
        }

        cout << "2";
        for (int i = 1; i < n; ++i) {
            cout << " " << vals[i];
        }
        cout << endl;
        fflush(stdout);
        int res;
        cin >> res;
        if (-1 == res) { break;}
     }

    return 0;
}