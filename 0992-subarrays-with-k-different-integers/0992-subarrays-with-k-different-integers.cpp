class Solution {
public:
int helper(vector<int>& nums, int tar)
{
    unordered_map<int , int>mpp;
    int n = nums.size();
    int cnt = 0;


    int l =0 ;
    int r = 0;
    while(r<n)
    {
        mpp[nums[r]]++;
        while(mpp.size()>tar)
        {
            mpp[nums[l]]--;
            if(mpp[nums[l]]==0)
            {
                mpp.erase(nums[l]);

            }
            l++;
        }
        cnt+= (r-l+1);
        r++;
        
    }
    return cnt;

}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        int a = helper(nums , k);
        int b = helper(nums  ,k-1);
        return a-b;

    }
};