class Solution {
public:
bool isPoss(vector<int>& nums, int k, int mid)
{
    int cnt = 0;
    int sum =0;
    int n = nums.size();
    for( int i = 0 ; i<n ; i++)
    {
        if(sum+nums[i]>mid)
        {
            cnt++;
            sum   = nums[i];
        }
        else{
            sum+= nums[i];
        }
    }
    cnt++;
    if( cnt<=k)return true;
    return false;

}
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = INT_MIN;
        int high = 0;
        for( int i = 0 ; i<n ; i++)
        {
            low = max(low, nums[i]);
            high+= nums[i];
        }
        int ans = 0;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(isPoss(nums , k , mid))
            {
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};