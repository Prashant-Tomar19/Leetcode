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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1) {
            return head;
        }

        ListNode* start = head;
        ListNode* end = head;
        ListNode* prev = nullptr;
        ListNode* next_grp = nullptr;
        ListNode* temp = nullptr;
        bool change = true;

        while (start != nullptr) {
            end = start;

            for (int i = 1; i < k && end != nullptr; i++) {
                end = end->next;
            }

            if (end == nullptr) {
                break;
            }

            next_grp = end->next;
            temp = next_grp;

            ListNode* curr = start;
            while (curr != next_grp) {
                ListNode* a = curr->next;
                curr->next = temp;
                temp = curr;
                curr = a;
            }

            if (change) {
                head = end;
                change = false;
            } else {
                prev->next = end;
            }

            prev = start;
            start = next_grp;
        }

        return head;
    }
};