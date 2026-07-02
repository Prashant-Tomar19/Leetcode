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
    ListNode *detectCycle(ListNode *head) {
        ListNode* temp=head;
        ListNode* temp1=head;
        while(temp!=nullptr && temp1!=nullptr){
            temp1=temp1->next;
            if(temp1!=nullptr){
                temp1=temp1->next;
            }
            else{
                return nullptr;
            }
            temp=temp->next;
            if(temp==temp1){
                temp=head;
                break;
            }
        }
            if(temp!=nullptr && temp1!=nullptr){
                while(temp!=temp1){
                    temp=temp->next;
                    temp1=temp1->next;
                }
            return temp;
            }
        return nullptr;
    }
};