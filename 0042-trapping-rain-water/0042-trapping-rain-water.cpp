class Solution {
public:
    int trap(vector<int>& nums) {
        int n= nums.size();
        vector<int>mxl( n, 0);
        vector<int>mxr( n, 0);
        mxl[0]= nums[0];
        mxr[n-1]= nums[n-1];
        for( int i = 1; i<n; i++)
        {
            mxl[i]= max(nums[i], mxl[i-1]);
        }
        for( int i = n-2 ; i>=0 ; i--)
        {
            mxr[i]= max(nums[i], mxr[i+1]);
        }
        int water = 0;
        for( int i = 0 ; i<n; i++)
        {
            water+= abs(min(mxl[i], mxr[i])-nums[i]);
        }
        return water;
    }
};