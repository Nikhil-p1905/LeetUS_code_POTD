class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obs) {
        map<vector<int>,int> mp;

        for(auto x:obs)
        mp[x]++;

        int ans=0;
        //NESW
        int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        int x=0,y=0,k=0;  

        for(auto c:commands)
        {
            if(c==-1)
            {
                k=(k+1)%4;
            }
            else if(c==-2)
            {
                // k=(k+3)%4;
                k=(k-1+4)%4;
            }
            else{
                for(int j=0;j<c;j++)
                {
                    int new_x = x+dir[k][0];
                    int new_y = y+dir[k][1];

                    if(mp.count({new_x,new_y}))
                    {
                        break;
                    }

                    x=new_x,y=new_y;

                    ans=max(ans,x*x+y*y);
                }
            }
        }
        return ans;      

    }
};
