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
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        int count =0;
        while(fast!=nullptr){
            count++;
            fast=fast->next;
        }
        k=k%count;
        if(k==0){
            return head;
        }
        fast=head;
        for(int i=0; i<count-1;i++){
            if(i<count-k-1){
                slow=slow->next;
            }
            fast=fast->next;
        }
        fast->next=head;
        head=slow->next;
        slow->next=nullptr;
        return head;
    }
};