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
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* h1 = head;
        ListNode* h2 = slow->next;

        slow->next = nullptr;

        // reverse h2
        ListNode* p1 = nullptr;
        ListNode* p2 = h2;
        ListNode* p3 = nullptr;


        while (p2) {
            p3 = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = p3;
        }
        h2 = p1;

        head = h1;

        // reusing p1
        while (h1 && h2) {
            p1 = h2;
            h2 = h2->next;

            p1->next = h1->next;
            h1->next = p1;
            h1 = p1->next;
        }
        
    }
};
