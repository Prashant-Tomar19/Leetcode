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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode ans(0);
        struct compare{
            bool operator()(ListNode* a, ListNode* b){
                return a->val > b->val;
            }
        };
        priority_queue<ListNode*, vector<ListNode*>, compare>pq;
        for(int i=0; i<lists.size(); i++){
            if(lists[i]!=nullptr){
                pq.push(lists[i]);
            }
        }
        ListNode* tail=&ans;
        while(pq.size()!=0){
            ListNode* temp=pq.top();
            tail->next=temp;
            tail=tail->next;
            if(temp->next!=nullptr){
                pq.push(temp->next);
            }
           pq.pop();
        }
        return ans.next;
    }
};