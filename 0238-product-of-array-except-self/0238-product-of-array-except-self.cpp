class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>leftP(n, 1);
        vector<int>rightP( n , 1);
        int lefty = 1;
        int righty = 1;
        for( int i = 1 ; i<n ; i++)
        {
             lefty = lefty*nums[i-1];
             leftP[i]= lefty;
        }
        for( int i = n-2 ; i>= 0 ; i--)
        {
            righty = righty *nums[i+1];
            rightP[i]= righty;
        }
        vector<int>final( n , 0);
        for( int i  =0 ; i <n ; i++)
        {
            final[i]= leftP[i]*rightP[i];
        }
        return final;
    }
};