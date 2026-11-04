/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int pos = 1;
        ListNode* before = NULL;
        ListNode* t = head;

        if (head == NULL)
            return NULL;
        if (left == right)
            return head;

        while (t != NULL) {
            if (pos < left) {
                before = t;
                t = t->next;
                pos++;
                continue;
            }
            int timer = (right - left) + 1;
            ListNode* curr = t;
            ListNode* prev = NULL;
            while (timer--) {
                ListNode* nex = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nex;
            }

            t->next = curr;
            if (before) {
                before->next = prev;
                return head;
            }
            return prev;
        }
        return NULL;
    }
};