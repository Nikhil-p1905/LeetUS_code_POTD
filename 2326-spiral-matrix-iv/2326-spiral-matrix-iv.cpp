class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m,vector<int>(n,-1));
        int row_start=0, row_end = m-1, col_start= 0, col_end=n-1;

        while(head && row_start<=row_end && col_start<=col_end)
        {
            //top row
            for(int j=col_start;j<=col_end && head;j++)
            {
                ans[row_start][j] = head->val;
                head= head->next;
            }
            row_start++;

            //left col
            for(int i=row_start;i<=row_end && head;i++)
            {
                ans[i][col_end] = head->val;
                head= head->next;
            }
            col_end--;

            //bottom row -> traverse right to left 
            for(int j=col_end;j>=col_start && head;j--)
            {
                ans[row_end][j]= head->val;
                head = head->next;
            }
            row_end--;

            //right col -> bottom to top

            for(int i=row_end;i>=row_start && head;i--)
            {
                ans[i][col_start] = head->val;
                head= head->next;
            }

            col_start++;

        }

        return ans;

    }
};