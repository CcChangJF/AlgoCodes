

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
#include <string.h>
#include <unordered_map>

using namespace std;




 struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 };

class Solution1 {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) { return NULL;}
        unordered_map<RandomListNode *, RandomListNode*> m;
        set<RandomListNode*> s;
        RandomListNode *ori = head;
        RandomListNode *newHead = new RandomListNode(head->label);
        RandomListNode *cpy = newHead;
        m.insert(make_pair(ori, cpy));
        s.insert(ori);
        while(NULL != ori -> next && 0 == s.count(ori -> next)) {
            ori = ori -> next;
            cpy -> next = new RandomListNode(ori->label);
            cpy = cpy -> next;
            s.insert(ori);
            m.insert(make_pair(ori, cpy));
        }
        RandomListNode *lastNode = NULL;
        if(NULL != ori -> next) {
            lastNode = cpy;
            cpy -> next = m[ori -> next];
        }
        ori = head;
        cpy = newHead;
        while (cpy != lastNode) {
            cpy -> random = m[ori -> random];
            ori = ori -> next;
            cpy = cpy -> next;
        }
        return newHead;
    }
};

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) { return NULL;}
        RandomListNode *slow = head;
        RandomListNode *fast = head;
        while(NULL != fast && NULL != fast -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
            if (fast == slow) { break;}
        }
        RandomListNode *last = NULL;
        if (fast == slow) {
            fast = head;
            while (fast != slow) {
                last = slow;
                fast = fast -> next;
                slow = slow -> next;
            }
        }
        //copy 
        RandomListNode *p = head;
        
        while(p != last) {
            RandomListNode *add = new RandomListNode(p -> label);
            add -> next = p -> next;
            p -> next = add;
            p = add -> next;
        }
        RandomListNode *loopstart = NULL;
        if (NULL != last) {
            RandomListNode *add = new RandomListNode(p -> label);
            add -> next = p -> next;
            p -> next = add;
            loopstart = add -> next -> next;
        }
        p = head;
        RandomListNode *nxt = NULL;
        while (last != p) {
            nxt = p -> next;
            if (NULL == p -> random) {
                nxt -> random = NULL;
            }
            else {
                nxt -> random = p -> random -> next;
            }
            p = nxt -> next;
        }
        RandomListNode *looplast = NULL;
        if (NULL != last) {
            nxt = p -> next;
            nxt -> random = p -> random -> next;
            looplast = nxt;
        }
        
        //break
        RandomListNode *newHead = head -> next;
        slow = head;
        fast = slow -> next;
        p = fast -> next;
        while(last != p) {
            slow -> next = p;
            fast -> next = p -> next;
            slow = slow -> next;
            fast = fast -> next;
            p = p -> next -> next;
        }
        if (NULL != last) {
            slow -> next = p;
            fast -> next = p -> next;
            looplast -> next = loopstart;
        }
        else {
            slow -> next = p;
            fast -> next = NULL;
        }
        return newHead;
    }
};

class Solution2 {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) { return NULL;}

        //copy 
        RandomListNode *p = head;
        
        while(p != NULL) {
            RandomListNode *add = new RandomListNode(p -> label);
            add -> next = p -> next;
            p -> next = add;
            p = add -> next;
        }
        p = head;
        RandomListNode *nxt = NULL;
        while (NULL != p) {
            nxt = p -> next;
            if (NULL == p -> random) {
                nxt -> random = NULL;
            }
            else {
                nxt -> random = p -> random -> next;
            }
            p = nxt -> next;
        }
        
        //break
        RandomListNode *newHead = head -> next;
        RandomListNode *slow = head;
        RandomListNode *fast = slow -> next;
        p = fast -> next;
        while(NULL != p) {
            slow -> next = p;
            fast -> next = p -> next;
            slow = slow -> next;
            fast = fast -> next;
            p = p -> next -> next;
        }
        slow -> next = NULL;
        fast -> next = NULL;
        return newHead;
    }
};
int main() {

    return 0;
}
