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
    bool hasCycle(ListNode *head) {
        ListNode* temp=head;
        ListNode* temp1=head;
        while(temp!=nullptr && temp1!=nullptr){
            temp1=temp1->next;
            if(temp1!=nullptr){
                temp1=temp1->next;
            }
            else{
                return false;
            }
            temp=temp->next;
            if(temp==temp1){
                return true;
            }
        }
        return false;
    }
};