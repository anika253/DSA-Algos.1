class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
       int n = nums.size();
       vector<int>final;
       for( int i = 0 ; i<nums.size(); i++)
       {if(nums[i]==1){
        final.push_back(i);
       }
       }
       for( int i = 1; i<final.size(); i++)
       {
        if(final[i]-final[i-1] <=k)
        {
            return false;
        }

       }


return true;
    }
};