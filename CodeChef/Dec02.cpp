
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

using namespace std;


int main() {
    srand(time(NULL));
    int a = rand() % 3 + 1;
    cout << a << endl;
    fflush(stdout);
    int b;
    cin >> b;
    cout << (6 - a - b) << endl;
    fflush(stdout);
    return 0;
}