class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n= nums.size();
        int cnd1 = 0;
        int cnd2 = 0;
        int cnt1 = 0;
        int cnt2 = 0;
        for( int i = 0 ; i<n; i++)
        {
            if( cnt1==0 && nums[i]!= cnd2)
            {
                cnd1 = nums[i];
                cnt1=1;
               
            }
           else  if( cnt2==0 &&  nums[i]!= cnd1)
            {
                cnd2 = nums[i];
                cnt2++;
            }
            else if( nums[i]==cnd1)
            {
                cnt1++;
            }
            else if(nums[i]==cnd2)
            {
                cnt2++;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
            

        }
        vector<int>final;
       int x1 = 0;
       int x2= 0;
       for( int i =0 ; i<n ; i++)
       {
        if( nums[i]==cnd1)
        {
            x1++;
        }
        else if( nums[i]==cnd2)
        {
            x2++;
        }
       }
       if( x1> n/3)
       {
        final.push_back(cnd1);
       }
       if(x2>n/3)
       {
        final.push_back(cnd2);
       }
return final;
    }
};