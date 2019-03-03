
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

    ListNode *reverse(ListNode *head, int n) {
        if (NULL == head) {
            return head;
        }
        ListNode *p = head;
        ListNode *cur = head;
        ListNode *prev = NULL;
        int cnt = 0;
        while (cnt++ < n && NULL != p) {
            cur = p;
            p = p -> next;
            cur -> next = prev;
            prev = cur;
        }
        head -> next = p;
        return cur;
    }
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m >= n) { return head;}
        if (m <= 0 || n <= 0) { return head;}
        ListNode *newHead = new ListNode(0);
        newHead -> next = head;
        int cnt = 1;
        ListNode *p = newHead;
        while (cnt++ < m && NULL != p) {
            p = p -> next;
        }
        if (NULL != p) {
            p -> next = reverse(p -> next, n - m + 1);
        }
        return newHead -> next;
    }
};

int main() {
    // m = 0, n = 0
    // m < 0, n < 0
    // m > n
    // m = n
    // m > length of list
    // n > length of list
    return 0;
}