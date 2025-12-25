class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int pre = 1;
        int suff = 1;
        int ans = 0;
        for(int i = 0 ; i<n; i++)
        {
            pre*= nums[i];
            suff*= nums[n-1-i];
            ans = max( ans , max(pre, suff));
        }
      return ans;

    }
};