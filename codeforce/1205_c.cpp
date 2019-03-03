
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string.h>


using namespace std;

const int maxLen = 2001;
int nums[maxLen];
int opers[maxLen];
int operIndex[maxLen];
int operAnd[maxLen];

int main() {
    int n;
    while (cin >> n) {
        memset(nums, 0, maxLen * sizeof(int));
        memset(opers, 0, maxLen * sizeof(int));
        memset(operIndex, 0, maxLen * sizeof(int));
        memset(operAnd, 0, maxLen * sizeof(int));
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        int index = n - 1;
        int count = 0;
        int sumAdd = 0;
        // if (nums[index] < n - 1) {
        //     opers[count++] = 1;
        //     operIndex[count++] = index + 1;
        //     int add = n - 1 - nums[index];
        //     operAnd[count++] = add;
        //     sumAdd += add;
        //     --index;
        // }
        while (index >= 0) {
            if ((nums[index] + sumAdd) % n != index) {
                opers[count] = 1;
                // cout << opers[count] << endl;
                operIndex[count] = index + 1;
                int add = (index + n - (nums[index] + sumAdd) % n) % n;
                operAnd[count] = add;
                ++count;
                sumAdd += add; 
            }
            --index;
        }
        cout << count + 1 << endl;
        for (int i = 0; i < count; ++i) {
            cout << opers[i] << " " << operIndex[i] << " " << operAnd[i] << endl;
        }
        cout << "2 " << n << " " << n << endl;
    }
    return 0;
}