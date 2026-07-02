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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* temp=head;
        int n=0;
        while(temp!=nullptr){
            n++;
            temp=temp->next;
        }
        if(n==0 || n==1){
            return head;
        }
        
        ListNode* even_index=head->next;
        ListNode* tempp=even_index;
        temp=head;
        for(int i=0; i<(n-1)/2; i++){
            temp->next=temp->next->next;
            tempp->next=tempp->next->next;
            temp=temp->next;
            tempp=tempp->next;
        }
        temp->next=even_index;
        return head;
    }
};