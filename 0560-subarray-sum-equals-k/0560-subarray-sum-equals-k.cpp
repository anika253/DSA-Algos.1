class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n= nums.size();
        int r = 0;
        unordered_map<int  ,int>mpp;
        mpp[0]=1;
        int sum = 0;
        int cnt = 0;
        while(r<n)
        {
            sum+= nums[r];
            if(mpp.find(sum-k)!= mpp.end())
            {
                cnt+= mpp[sum-k];
            }
      mpp[sum]++;
      r++;

        }
return cnt;
    
    }
};