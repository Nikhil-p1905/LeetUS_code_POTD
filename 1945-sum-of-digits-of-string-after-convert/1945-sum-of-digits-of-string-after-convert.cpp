class Solution {
public:
    int getLucky(string s, int k) {
        int n=s.size();
        int sum=0;
        for(auto c:s)
        {
            int val = c-'a'+1;
            while(val)
            {
                sum+= val%10;
                val/=10;
            }
        }

        for(int i=1;i<k;i++) //(till k-1)
        {
            int temp=0;
            while(sum)
            {
                temp+=sum%10;
                sum/=10;
            }
            sum=temp;
        }

        return sum;

    }
};
