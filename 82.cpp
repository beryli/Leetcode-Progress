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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* sentinel = new ListNode(0, head);
        ListNode* pred = sentinel;
        ListNode* del_ptr;
        while (head && head->next) {
            if (head->val == head->next->val) {
                while (head->next && head->val == head->next->val) {
                    del_ptr = head;
                    head = head->next;
                    delete del_ptr;
                }
                pred->next = head->next;
                del_ptr = head;
                head = head->next;
                delete del_ptr;
            } else {
                pred = head;
                head = head->next;
            }
        }
        return sentinel->next;
    }
};