
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (NULL == head) {return head;}
        ListNode *newHead = new ListNode(0);
        newHead -> next = head;
        ListNode *prev = newHead;
        while (NULL != prev -> next && prev -> next -> val < x) {
            prev = prev -> next;
        }
        ListNode *p = prev -> next;
        ListNode *parent = prev;
        while (NULL != p) {
            while (NULL != p && p -> val >= x) {
                p = p -> next;
                parent = parent -> next;
            }
            if (NULL != p ) {
                // insert 
                parent -> next = p -> next;
                p -> next = prev -> next;
                prev -> next = p;
                prev = prev -> next;
                p = parent -> next;
            }
        }
        return newHead -> next;
    }
};

int main() {
    // null
    return 0;
}