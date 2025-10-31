class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n =  nums.size();
        unordered_map<int , int >mpp;
        for( auto it: nums)
        {
            mpp[it]++;
        }
        vector<int>ans;
        for( auto it: mpp)
        {
            if(mpp[it.first]>1)
            {
                ans.push_back(it.first);
            }
        }
        return ans;
        

        
    }
};