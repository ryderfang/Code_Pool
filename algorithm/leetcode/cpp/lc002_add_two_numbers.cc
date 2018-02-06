#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        int carry = 0;
        ListNode* prev = NULL;
        ListNode* head = NULL;
        while (p1 != NULL || p2 != NULL) {
            ListNode* p_sum = new ListNode(0);
            if (p1 == NULL) p_sum->val = p2->val;
            else if (p2 == NULL) p_sum->val = p1->val;
            else p_sum->val = p1->val + p2->val;
            p_sum->val += carry;
            carry = p_sum->val / 10;
            p_sum->val %= 10;
            if (p1) p1 = p1->next;
            if (p2) p2 = p2->next;
            if (prev) prev->next = p_sum;
            else head = p_sum;
            prev = p_sum;
        }
        if (carry) {
            ListNode* p_sum = new ListNode(carry);
            prev->next = p_sum;
        }
        return head;
    }
};

int main() {
    Solution sol;
    
    ListNode* p1_1 = new ListNode(1);
    ListNode* p1_2 = new ListNode(8);
    p1_1->next = p1_2;

    ListNode* p2_1 = new ListNode(0);

    cout << sol.addTwoNumbers(p1_1, p2_1) << endl;
    return 0;
}
