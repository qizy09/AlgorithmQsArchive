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
        int t = 0;
        ListNode* p = l1, *q = l2, *ans, *curr = NULL;
        while (p && q)
        {
            t += p->val + q->val;
            if (curr)
            {
                curr-> next = new ListNode(t % 10);
                curr = curr->next;
            }
            else
                ans = (curr = new ListNode(t % 10));
            t = t/ 10;
            p = p-> next; q = q-> next;
        }
        if (!p) p = q;
        while (p) {
            t += p->val;
            if (curr)
            {
                curr-> next = new ListNode(t % 10);
                curr = curr->next;
            }
            else
                ans = (curr = new ListNode(t % 10));
            t = t/ 10;
            p = p-> next;
        }
        if (t) {
            curr-> next = new ListNode(t % 10);
            curr = curr->next;
        }
        return ans;
    }
};
