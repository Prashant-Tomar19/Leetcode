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
    bool isPalindrome(ListNode* head) {
        ListNode* temp=head;
        int n=0;
        while(temp!=nullptr){
            n++;
            temp=temp->next;
        }
        temp=head;
        if(n%2==0){
            for(int i=0; i<n/2; i++){
                temp=temp->next;
            }
        }
        else{
            for(int i=0; i<=n/2; i++){
                temp=temp->next;
            }
        }
        
        ListNode* a=nullptr;
        for(int i=0;i<n/2; i++){
            ListNode* nextNode = temp->next;
            temp->next=a;
            a=temp;
            temp=nextNode;
        }
        temp=head;
        while(a!=nullptr){
            if(a!=nullptr && temp->val!=a->val){
                return false;
            }
            temp=temp->next;
            a=a->next;
        }
        return true;
    }
};