//Description



//TestCase
/*

*/

//Wrong case
/*

*/


/*
how to solve
minimium heap

*/

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
private:
    class node{
    private:
        ListNode *val;
        int index;
    public:
        node(ListNode *a, int b) {
            val = a;
            index = b;
        }
        node() {
            val = NULL;
            index = 0;
        }
        ListNode* getVal() {
            return val;
        }
        int getIndex() {
            return index;
        }
    };
    class MyCompare{
    public:
        bool operator()(node a, node b) {
            return (a.getVal() -> val > b.getVal() -> val);
        }
    };
public:

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<node, vector<node>, MyCompare> pq = 
            priority_queue<node, vector<node>, MyCompare>();
        vector<ListNode *> index = vector<ListNode *>(lists.size());
        for (int i = 0; i < lists.size(); ++i) {
            if (NULL != lists[i]) {
                index[i] = lists[i];
                pq.push(node(index[i], i));
                index[i] = index[i] -> next;
            }
        }


        ListNode *head = new ListNode(0);
        ListNode *p = head;
        while(!pq.empty()) {
            node cur = pq.top();
            int curIndex = cur.getIndex();
            pq.pop();
            p -> next = cur.getVal();
            p = p -> next;
            if (NULL != index[curIndex]) {
                pq.push(node(index[curIndex], curIndex));
                index[curIndex] = index[curIndex] -> next;
            }
        }

        return head -> next;
    }
};
 
class Solution1 {
public:
    void insert(vector<ListNode*> &heap, vector<int> &pq, ListNode *ins, int index, int &cap) {
        cap = cap + 1;
        heap[cap] = ins;
        pq[cap] = index;
        swim(heap, cap, pq);
        return;
    }

    void exch(vector<ListNode *> &heap, vector<int> &pq, int node, int parent) {
        ListNode *t = heap[node];
        heap[node] = heap[parent];
        heap[parent] = t;

        int index = pq[node];
        pq[node] = pq[parent];
        pq[parent] = index;
        return;
    }

    void swim(vector<ListNode *> &heap, int node, vector<int> &pq) {
        while(node > 1 && heap[node] -> val < heap[node/2] -> val) {
            exch(heap, pq, node, node/2);
            node = node / 2;
        }
        return;
    }

    void sink(vector<ListNode *> &heap, int node, int cap, vector<int> &pq) {
        while (node * 2 <= cap) {
            int left = node * 2;
            if (left < cap && heap[left] -> val >= heap[left + 1] -> val) {
                ++left;
            }
            if (heap[node] -> val > heap[left] -> val) {
                exch(heap, pq, node, left);
                node = left;
            }
            else {
                break;
            }
        }
        return;
    }

    ListNode* delMin(vector<ListNode *> &heap, vector<int> &pq, int &index, int &cap) {
        ListNode *ret = heap[1];
        index = pq[1];
        exch(heap, pq, 1, cap);
        cap = cap - 1;
        sink(heap, 1, cap, pq);
        return ret;
    }

    bool empty(int cap) {
        return (0 == cap);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (0 == lists.size()) {return NULL;}
        vector<ListNode *> heap = vector<ListNode *>(lists.size() + 1);
        vector<int> pq = vector<int>(lists.size() + 1);
        vector<ListNode *> index = vector<ListNode *>(lists.size());
        int cap = 0;
        for (int i = 0; i < lists.size(); ++i) {
                if (NULL != lists[i]){
                    index[i] = lists[i];
                    insert(heap, pq, lists[i], i, cap);
                    index[i] = index[i] -> next;
                }
        }
        ListNode *head = new ListNode(0);
        ListNode *p = head;
        while(!empty(cap)) {
            int curIndex = 0;
            p -> next = delMin(heap, pq, curIndex, cap);
            p = p -> next;
            if (NULL != index[curIndex]) {
                insert(heap, pq, index[curIndex], curIndex, cap);
                index[curIndex] = index[curIndex] -> next;
            }
        }
        return head -> next;
    }
};

int main() {
    Solution s;


    return 0;
}