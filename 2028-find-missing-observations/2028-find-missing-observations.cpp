class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum=0;
        for(auto x:rolls)
         sum+=x;

        int rem_sum = mean*(n+m) - sum;
        if(rem_sum<1*n || rem_sum>6*n)
            return {};

        int d = rem_sum/n;
        int rem = rem_sum%n;

        vector<int> ans(n,d);
        for(int i=0;i<rem;i++)
        {
            ans[i]++;
        }

        return ans;
    }
};