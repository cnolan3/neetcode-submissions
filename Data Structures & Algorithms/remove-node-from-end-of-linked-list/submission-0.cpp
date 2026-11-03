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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* tmpHead = new ListNode(-1, head);
        ListNode* p1 = head;
        ListNode* p2 = nullptr;

        int i = 0;

        while (p1) {
            if (!p2 && i == n - 1) {
                p2 = tmpHead;
            } else if (p2) {
                p2 = p2->next;
            }

            p1 = p1->next;
            i++;
        }

        p2->next = p2->next->next;
        
        return tmpHead->next;
    }
};
