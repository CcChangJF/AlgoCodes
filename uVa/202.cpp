
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>


using namespace std;

class Solution{
public:
    string ans;
    int repeatLength;
    void cal(int n, int m) {
        vector<char> ansVec = vector<char>();
        repeatLength = 0;
        if (0 == m) { return; }
        int num = n / m;
        if (0 == num) {
            ansVec.insert(ansVec.begin(), num + '0');
        }
        while (0 != num) {
            ansVec.insert(ansVec.begin(), num % 10 + '0');
            num /= 10;
        }
        map<int, int> mods = map<int, int>();
        vector<int> digits = vector<int>();
        int dec = n % m;
        do {
            num = dec * 10 / m;
            mods[dec] = num;
            digits.push_back(dec);
            dec = dec * 10 % m;
        } while(0 == mods.count(dec));
        ansVec.push_back('.');
        int index = 0;
        while (index < digits.size()) {
            if (dec != digits[index]) {
                ansVec.push_back(mods[digits[index]] + '0');
            }
            else {
                break;
            }
            ++index;
        }
        string temp = string(ansVec.begin(), ansVec.end());
        cout << "temp: " << temp << endl;
        // if (0 == dec && digits.size() > 0) {
        //     ansVec.push_back(mods[digits[index++]] + '0');
        // }
        // cout << "index: " << index << ", " << digits.size() << endl;
        ansVec.push_back('(');
        repeatLength = max((int)digits.size() - index, 1);
        int lastElem = min(index + 50, (int)digits.size());
        while (index < lastElem ) {
            ansVec.push_back(mods[digits[index++]] + '0');
        }
        // if (0 == dec) {
        //     ansVec.push_back('0');
        // }
        if (repeatLength > 50) {
            ansVec.push_back('.');
            ansVec.push_back('.');
            ansVec.push_back('.');
        }
        ansVec.push_back(')');
        ans = string(ansVec.begin(), ansVec.end());
        return;
    }
};


int main() {
    Solution s;
    int n, m;
    while (cin >> n >> m) {
        s.cal(n, m);
        cout << n << "/" << m << " = " << s.ans << endl;
        cout << "   " << s.repeatLength << " = number of digits in repeating cycle" << endl;
        cout << endl;
    }
    return 0;
}