#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>

using namespace std;

class Solution {
    string getStr(int a, int b) {
        string strB = "";
        string strA = "";
        while(0 != b || 0 != a) {
            if (a % 10 != b % 10) {
                strA.insert(strA.begin(), a % 10 + '0');
                a /= 10;
            }
            else {
                strB.insert(strB.begin(), b % 10 + '0');
                strA.insert(strA.begin(), a % 10 + '0');
                a /= 10;
                b /= 10;
            }
        }
        return strA + " + " + strB + " = ";
    }

    void putToRes(vector<int> &res, int tarTemp, int b, int power) {
        if (10 != tarTemp % 11) {
            int k = tarTemp % 11;
            int a = tarTemp / 11;
            res.push_back((a * 10 + k) * power + b);
        }
    }
public:
    vector<int> powers;
    Solution(vector<int> &nums) {
        powers = vector<int>(nums.begin(), nums.end());
    }
    vector<string> sumToTarget(int target) {

        set<int> unique = set<int>();
        vector<int> res = vector<int>();
        if (10 != target % 11) {
            int k = target % 11;
            int a = target / 11;
            res.push_back(a * 10 + k);
        }

        if (0 == target % 2) {
            for (int i = 0; i < powers.size() && powers[i] <= target; ++i) {
            //for (int i = 0; powers[i] < target; ++i) {
                // 无进位
                int b = target % powers[i] / 2;
                int tarTemp = target / powers[i];
                putToRes(res, tarTemp, b, powers[i]);
                // 进位
                if (1 == target / powers[i]) { continue;}
                b = (target % powers[i] + powers[i]) / 2;
                tarTemp = target / powers[i] - 1;
                putToRes(res, tarTemp, b, powers[i]);
            }
        }
        sort(res.begin(), res.end());
        vector<string> resStr = vector<string>();
        if (0 == res.size()) {
            return resStr;
        }
        int t = target;
        string strTar = "";
        while (0 != t) {
            strTar.insert(strTar.begin(), t % 10 + '0');
            t /= 10;
        }
        int pivot = res[0];
        resStr.push_back(getStr(res[0], target - res[0]) + strTar);
        for (int i = 1; i < res.size(); ++i) {
            if (res[i] != pivot) {
                resStr.push_back(getStr(res[i], target - res[i]) + strTar);
                pivot = res[i];
            }
        }
        return resStr;
    }
};


int main() {
    int n;
    vector<int> powers = vector<int>();
    int cnt = 1;
    int count = 10;
    while (cnt < 10) {
        powers.push_back(count);
        // cout << count << endl;
        count *= 10;
        ++cnt;
    }
    Solution s(powers);
    while(cin >> n) {
        vector<string> res = s.sumToTarget(n);
        cout << res.size() << endl;
        for (int i = 0; i < res.size(); ++i) {
            cout << res[i] << endl;
        }

    }

    return 0;
}