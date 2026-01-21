class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int , int>mpp;
        int l = 0;
        int r = 0;
        int len = 0;
       long long sum = 0;
       long long final = 0;
        while(r<n)
        {
            mpp[nums[r]]++;
            sum+= nums[r];
            while(r-l+1 >k)
            {
                mpp[nums[l]]--;
                sum-=nums[l];
                if(mpp[nums[l]]==0)
                {
                    mpp.erase(nums[l]);

                }
                l++;
            }
            if(r-l+1==k && mpp.size()==k)
            {
                final = max(final , sum);
            }
            r++;
        }
        return final;
    }
};