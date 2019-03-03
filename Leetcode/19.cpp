#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
 

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (n < 0) {return head;}
        if (NULL == head) {return head;}
        int k = 0;
        ListNode *p = head;
        while (NULL != p && k < n) {
            ++k;
            p = p -> next;
        }
        if (k == n) { 
            if (NULL != p) {
                ListNode *prev = head;
                while(NULL != p -> next) {
                    prev = prev -> next;
                    p = p -> next;
                }
                ListNode *del = prev -> next;
                prev -> next = del -> next;
                del -> next = NULL;
                free(del);
            }
            else {
                ListNode *newHead = head -> next;
                head -> next = NULL;
                free(head);
                head = newHead;
            }
        }
        return head;
    }
};

int main() {
    Solution s;

    ListNode *head = new ListNode(1);
    ListNode *p = head;
    p->next = new ListNode(2);
    p = p->next;
    p->next = new ListNode(3);
    p = p->next;
    p->next = new ListNode(4);
    p = p->next;
    p->next = new ListNode(5);
    ListNode *newHead = s.removeNthFromEnd(head, 2);
    p = newHead;
    while(NULL != p) {
        cout << p->val << " ";
        p = p->next;
    }

    return 0;
}