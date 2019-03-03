#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode *newHead = new ListNode(0);
        ListNode *p = newHead;
        while(NULL != p1 && NULL != p2) {
            if (p1 -> val < p2 -> val) {
                p -> next = p1;
                p1 = p1 -> next;
            }
            else {
                p -> next = p2;
                p2 = p2 -> next;
            }
            p = p -> next;
        }
        if (NULL != p1) {
            p -> next = p1;
        }
        if (NULL != p2) {
            p -> next = p2;
        }
        return newHead -> next;
    }
};

int main() {


    return 0;
}