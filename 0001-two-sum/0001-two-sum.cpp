class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int >mpp;
        vector<int>ans;
        for(int i = 0 ; i<nums.size(); i++)
        {
            int comp = target-nums[i];
            if(mpp.find(comp)!= mpp.end())
            {
                ans.push_back(mpp[comp]);
                ans.push_back(i);
                return ans ;
            }
            mpp[nums[i]]=i;
        }
        return ans;
    }
};