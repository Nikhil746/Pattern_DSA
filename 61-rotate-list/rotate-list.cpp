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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return NULL;
        int count = 1, n = 1;
        ListNode* curr = head;
        while(curr!=NULL && curr->next != NULL) {
            curr = curr->next;
            n++;
        }

        k = k%n;
        if(k == 0) return head;

        ListNode* t = head;
        while(t != NULL) {
            if(n-k == count) break;
            count++;
            t = t->next;
        }

        curr->next = head;
        ListNode* res = t->next;
        t->next = NULL;
        
        return res;
    }
};