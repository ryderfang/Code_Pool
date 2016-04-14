#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <stack>
#include <string>
#include <vector>
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* p = l1, *q = l2;
        ListNode* head = NULL;
        ListNode* pre = head;
        ListNode* cur = NULL;
        while (p != NULL && q != NULL) {
            if (p->val <= q->val) {
                cur = new ListNode(p->val); 
                p = p->next;
            } else {
                cur = new ListNode(q->val);
                q = q->next;
            }
            if (head == NULL) pre = head = cur;
            else {
                pre->next = cur; 
                pre = cur; 
            }
        }
        while (p != NULL) {
            cur = new ListNode(p->val);
            if (head == NULL) pre = head = cur;
            else {
                pre->next = cur;
                pre = cur;
            }
            p = p->next;
        }
        while (q != NULL) {
            cur = new ListNode(q->val);
            if (head == NULL) pre = head = cur;
            else {
                pre->next = cur;
                pre = cur;
            }
            q = q->next;
        }
        return head;
    }
};

int main() {
    Solution sol;
    ListNode* l1 = new ListNode(1);
    ListNode* l1_2 = new ListNode(2);
    l1->next = l1_2;
    sol.mergeTwoLists(l1, NULL);
    return 0;
}
