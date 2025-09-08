class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n= nums.size();
        int cnt = 0;
        int cnd = 0;
        for( int i = 0 ; i<n ; i++)
        {
            if(cnt==0)
            {
                cnd  = nums[i];
            }
          if( nums[i]== cnd)
            {
                cnt++;
            }
            else 
            {
                cnt--;
            }

        }
        int x = 0;
        for( int i = 0 ; i< n ; i++)
        {
            if( nums[i]== cnd)
            {
                x++;
            }
        }
        if( x>= n/2)
        {
            return cnd;
        }
        return -1;
    }
};