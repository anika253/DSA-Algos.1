class Solution {
public:
bool isPossible(vector<int>&nums, int h , int mid)
{
    int n = nums.size();
    int cnt=0;
    for(int i = 0 ; i< n ; i++)
    {
        cnt+=(ceil)(double(nums[i])/mid);
    }
    return cnt<=h;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high= 0;
        for(int i =0 ;i<n ;i++)
        {  //low = min(low , piles[i]);
            high = max(high , piles[i]);
        }
        while(low<=high)
        {
             int mid = high+(low-high)/2;
             if(isPossible(piles, h , mid))
             {
                high = mid-1;
             }
             else{
                low = mid+1;
             }
             
        }
        return low;
    }
};