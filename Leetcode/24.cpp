
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

class Solution{
public:
    ListNode* swapPairs(ListNode* head) {
        if (NULL == head || NULL == head->next) {
            return head;
        }
        else {
            ListNode *newHead = new ListNode(0);
            ListNode *prev = newHead;
            prev -> next = head;
            ListNode *first = head;
            ListNode *sec = head -> next;
            while(NULL != first && NULL != sec) {
                first -> next = sec -> next;
                sec -> next = first;
                prev -> next = sec;
                prev = first;
                first = first -> next;
                if (NULL != first) {
                    sec = first -> next;
                }
            }
            return newHead -> next;
        }
    }
};

class Solution1{
public:
    ListNode* swapPairs(ListNode* head) {
        if (NULL == head || NULL == head->next) {
            return head;
        }
        else {
            ListNode *newHead = head -> next;
            head -> next = newHead -> next;
            newHead -> next = head;
            head -> next = swapPairs(head -> next);
            return newHead;
        }
    }

};

int main() {

    return 0;
}