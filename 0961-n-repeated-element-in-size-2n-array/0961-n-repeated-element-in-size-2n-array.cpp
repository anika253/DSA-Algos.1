class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int x= nums.size();
        int n = x/2;
        unordered_map<int , int>mpp;
        int ans= 0;
        for(auto it: nums)
        {
            mpp[it]++;
        }

for( auto it: mpp)
{
    if(it.second==n)
    {
        ans = it.first;
    }
}
return ans;


            }
};