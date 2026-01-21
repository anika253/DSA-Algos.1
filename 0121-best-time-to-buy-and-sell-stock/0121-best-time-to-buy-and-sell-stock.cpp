class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        int cp = INT_MAX;
        int profit = INT_MIN;
        for(int i = 0 ; i<n ; i++)
        {
            cp = min(cp , nums[i]);
            profit = max( profit , nums[i]-cp);
        }
        return profit;
    }
};