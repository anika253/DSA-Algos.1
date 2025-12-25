class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n= nums.size();
        vector<int>prefix(n, 1);
        vector<int>suffix(n, 1);
        int pre = 1;
        int suff = 1;
        for( int i = 1 ; i<n; i++)
        {
            pre*= nums[i-1];
            prefix[i]= pre;
        }
        for(int i = n-2 ; i>=0 ; i--)
        {
            suff*= nums[i+1];
            suffix[i]= suff;
        }
        vector<int>final(n, 1);
        for(int i = 0; i<n; i++)
        {
            final[i] = prefix[i]*suffix[i];
                    }
                    return final;

    }
};