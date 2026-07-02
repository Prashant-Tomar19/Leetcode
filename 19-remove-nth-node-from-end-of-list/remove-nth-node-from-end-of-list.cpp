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
        ListNode* temp=head;
        ListNode* tempp=head;
        int count =0;
        while(temp!=nullptr){
            count++;
            temp=temp->next;
            if(count>n+1){
                tempp=tempp->next;
            }
        }
        
        if(count==1){
            return nullptr;
        }
        if(count==n){
            return head->next;
        }
        if(tempp->next!=nullptr){
            temp=tempp->next->next;
            tempp->next->next=nullptr;
            tempp->next=temp;
        }
        else{
            tempp->next=nullptr;
        }
        return head;
    }
        
};