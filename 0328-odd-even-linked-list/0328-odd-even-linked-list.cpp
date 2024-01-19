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
        if(head==NULL){
            return head;
        }
        ListNode* odd=NULL;
        ListNode* even=NULL;
        ListNode* evenl=NULL;
        ListNode* curr=head;
        int count=1;  
        while(curr!=NULL){
            if(count&1){
                if(odd==NULL){
                    odd=curr;
                }else{
                    odd->next=curr;
                    odd=odd->next;
                }
                
            }else{
                if(evenl==NULL){
                    evenl=curr;
                    even=curr;
                }else{
                    even->next=curr;
                    even=even->next;
                }
            }
            count++;
            curr=curr->next;
        }
        odd->next=evenl;
        if(even!=NULL){
            even->next=NULL;
        }
        return head;
    }
};