
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <limits>

using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
    long double calSlope(Point &a, Point &b) {
        //cout << a.x << " " << a.y << " " << b.x << " " << b.y << endl;
        if (a.x == b.x) {
            return numeric_limits<double>::max();
        }
        else {
            long double dx = a.x - b.x * 1.0;
            long double dy = a.y - b.y * 1.0;
            //cout << dx << " " << dy << endl;
            return dy / dx;
        }
    }


public:
    int maxPoints(vector<Point>& points) {
        if (points.size() <= 2) { return points.size(); }
        int numberOfPoints = points.size();
        vector<int> duplicate = vector<int>(numberOfPoints, 1);
        vector<vector<long double> > slope(numberOfPoints, vector<long double>(numberOfPoints, 0));
        for (int i = 0; i < numberOfPoints; ++i) {
            for (int j = i + 1; j < numberOfPoints; ++j) {
                slope[i][j] = calSlope(points[i], points[j]);
                slope[j][i] = slope[i][j];
                //cout << slope[i][j] << " ";
            }
            //cout << endl;
        }
        int maxNumInLine = 0;
        for (int i = 0; i < numberOfPoints; ++i) {
            int cntBase = 0;
            for (int j = numberOfPoints - 1; j >= 0; --j) {
                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    ++cntBase;
                    slope[i].erase(slope[i].begin() + j);
                }
            }
            sort(slope[i].begin(), slope[i].end());
            long double pivot = slope[i][0];
            // for (int j = 0; j < slope[i].size(); ++j) {
            //     cout << slope[i][j] << " ";
            // }
            // cout << endl;
            if (0 == slope[i].size()) {
                maxNumInLine = max(maxNumInLine, cntBase);
                continue;
            }
            //cout << cntBase << endl;
            int cnt = cntBase + 1;
            for (int j = 1; j < slope[i].size(); ++j) {
                if (pivot == slope[i][j]) {
                    ++cnt;
                }
                else {
                    maxNumInLine = max(maxNumInLine, cnt);
                    cnt = cntBase + 1;
                    pivot = slope[i][j];
                }
            }
            maxNumInLine = max(maxNumInLine, cnt);
        }
        return maxNumInLine;
    }
};

int main() {
    // vertical
    // points has same point?

    Solution s;
    vector<Point> points;
    points.push_back(Point(3,10));
    points.push_back(Point(0,2));
    points.push_back(Point(0,2));
    points.push_back(Point(3,10));
    cout << s.maxPoints(points) << endl;

    return 0;
}