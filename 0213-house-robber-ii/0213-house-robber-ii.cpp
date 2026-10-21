class Solution {
public:
    int helper(int n, vector<int>& x) {
        vector<int> dp(n, 0);
        dp[0] = x[0];
        for (int i = 1; i < n; i++) {
            int take = x[i];
            if (i > 1) take += dp[i - 2];
            int skip = dp[i - 1];
            dp[i] = max(take, skip);
        }
        return dp[n - 1];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        vector<int> nums1, nums2;
        for (int i = 0; i < n; i++) {
            if (i != n - 1) nums1.push_back(nums[i]); 
            if (i != 0)     nums2.push_back(nums[i]);  
        }

        int a = helper(n - 1, nums1);
        int b = helper(n - 1, nums2);
        return max(a, b);
    }
};