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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;

        ListNode* dummy = new ListNode(1000000);
        dummy->next = head;

        ListNode* temp=dummy;

        while(temp)
        {
            bool f=0;
            while(!st.empty() && st.top()->val<temp->val)
            {
                st.top()->next= NULL;
                st.pop();
                f=1;
            }

            if(f)
            {
                st.top()->next= temp;
            }
            st.push(temp);
            temp=temp->next;
        }

        return dummy->next;
    }
};