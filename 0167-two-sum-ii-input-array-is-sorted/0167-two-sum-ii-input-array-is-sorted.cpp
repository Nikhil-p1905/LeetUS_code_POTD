class Solution {
public:
    vector<int> twoSum(vector<int>& n, int target) {
        vector<int> ans;
        int start=0,end = n.size()-1;
        while(start<end){
            if(n[start]+n[end]==target)
            {
                ans.push_back(start+1);
                ans.push_back(end+1);
                return ans;
            }
            else if(n[start]+n[end]<target)
                start++;
            else
                end--;
        }
        return ans ;
        
    }
};