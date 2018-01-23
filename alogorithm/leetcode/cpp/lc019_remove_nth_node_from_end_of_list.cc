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
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> vn;
        int sz = 0;
        ListNode* p = head;
        while (p) {
            sz++;
            vn.push_back(p);
            p = p->next;
        }
        if (sz == n) {
            return vn[0]->next;
        } else {
            vn[sz-n-1]->next = vn[sz-n]->next; 
        }
        return head;
    }
};

