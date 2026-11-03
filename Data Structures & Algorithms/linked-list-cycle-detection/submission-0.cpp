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
    bool hasCycle(ListNode* head) {
        std::unordered_set<ListNode*> seenList;

        ListNode* cur = head;
        while (cur) {
            if (seenList.contains(cur->next)) {
                return true;
            }

            seenList.insert(cur);
            cur = cur->next;
        }

        return false;
    }
};
