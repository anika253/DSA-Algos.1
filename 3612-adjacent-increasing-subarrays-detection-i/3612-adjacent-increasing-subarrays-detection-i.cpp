class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
     int n = nums.size();
     int currC = 1;
     int prevC = 0;
     for(int i= 1; i<n ; i++)
     {
        if(nums[i]> nums[i-1])
        {
          currC++;
        }
        else{
            prevC = currC;
            currC=1;
        }
        if(currC>=2*k)
        {
            return true;
        }
        if(min(currC, prevC)>=k)
        {
            return true;
        }

     }
     return false;
    }
};