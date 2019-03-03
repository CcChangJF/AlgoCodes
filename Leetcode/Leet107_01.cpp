//Description



//TestCase
/*

*/

//Wrong case
/*

*/


/*
how to solve


*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if (name.length() > typed.length()) {return false;}
        int index_name = 0;
        int index_type = 0;
        while(index_name < name.length() - 1 && index_type < typed.length() - 1) {
            if (name[index_name] != name[index_name + 1]) {
                if (name[index_name] != typed[index_type]) {return false;}
                while(index_type < typed.length() - 1 && typed[index_type] == name[index_name]) {
                    index_type = index_type + 1;
                }
                index_name = index_name + 1;
            }
            else {
                index_name = index_name + 1;
                index_type = index_type + 1;
            }
        }
        if (index_name == name.length() - 1) {
            while(index_type < typed.length() && typed[index_type] == name[index_name]) {
                index_type = index_type + 1;
            }
            if (index_type == typed.length()) {return true;}

        } 
        return false;
    }
};

int main() {
    Solution s;
    cout << s.isLongPressedName("alex", "aalleex") << endl;
    cout << s.isLongPressedName("saeed", "ssaaedd") << endl;
    cout << s.isLongPressedName("leelee", "lleellleeeee") << endl;
    cout << s.isLongPressedName("laiden", "laiden") << endl;


    return 0;
}