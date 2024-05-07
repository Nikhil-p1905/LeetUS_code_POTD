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
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev=NULL, *curr=head;

        while(curr)
        {
            ListNode* nex= curr->next;

            curr->next=prev;
            prev=curr;
            curr=nex;
        }

        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
        head=reverse(head);

        ListNode* temp=head,*prev=NULL;
        int carry=0;
        while(temp)
        {
            int value= (temp->val*2+carry);
            temp->val= value%10;
            carry= value/10;
            prev=temp;
            temp=temp->next;
        }

        if(carry)
        {
            prev->next= new ListNode(carry);
        }

        return reverse(head);
    }
};