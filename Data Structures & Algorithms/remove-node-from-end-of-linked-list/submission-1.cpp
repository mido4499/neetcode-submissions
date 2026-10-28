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
        ListNode *end = head, *walk = head, *prev;
        ListNode* ret = head;
        for (int i = 0; i < n; i++){
            end = end->next;
        }

        if (end == nullptr){ // n = size of linked list, remove the first node
            head = head->next;
            walk->next = nullptr;
            delete walk;
            return head;
        }

        walk = walk->next;

        while (end->next != nullptr){
            prev = walk;
            walk = walk->next;
            end = end->next;
        }

        prev->next = walk->next;
        walk->next = nullptr;
        delete walk;

        return ret;
    }
};
