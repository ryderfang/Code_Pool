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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* res = head->next;
        ListNode* p = head;
        ListNode* q = p->next;
        ListNode* tp = NULL;
        while (p != NULL && q != NULL) {
            p->next = q->next;
            if (q->next && q->next->next) p->next = q->next->next;
            tp = q->next;
            q->next = p;

            p = tp;
            if (p) q = p->next;
            else q = NULL;
        }

        return res;
    }
};

