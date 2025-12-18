class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int , int>mpp;
   
        int total = 0;
        mpp[0]=0;

        for(int i = 0 ; i<n ; i++)
        {
            total+= nums[i];
              mpp[total]=i;
            if(mpp.find(total-target)!= mpp.end())
            {
                return { i, mpp[total-nums[i]]};
                break;

            }
          

        }
        return {-1, -1};

    }
};