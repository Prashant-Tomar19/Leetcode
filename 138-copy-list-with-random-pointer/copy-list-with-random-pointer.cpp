/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr){
            return nullptr;
        }
        if(head->next==nullptr){
            Node* ans=new Node(head->val);
            if(head->random==head){
                ans->random=ans;
            }
            return ans;
        }
        Node* left=head;
        Node* right=nullptr;
        Node* temp=nullptr;
        while(left!=nullptr){
            Node* ans=new Node(left->val);
            right=ans;
            temp=left->next;
            left->next=right;
            right->next=temp;
            left=temp;
        }
        left=head;
        right=head->next;
        while(left!=nullptr){
            if(left->random!=nullptr){
                temp=left->random;
                right->random=temp->next;
            }
            left=left->next->next;
            if(right->next!=nullptr){
                right=right->next->next;
            }
        }
        left=head;
        right=head->next;
        temp=right;
        while(left!=nullptr){
            left->next=left->next->next;
            if(right->next!=nullptr){
                right->next=right->next->next;
            }
            left=left->next;
            right=right->next;
        }
        return temp;
    }
};