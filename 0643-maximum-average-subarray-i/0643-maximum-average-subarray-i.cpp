class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxi =-1e9;
        int sum = 0;
        
        for( int i = 0 ; i<nums.size(); i++)
        {
            sum+= nums[i];
            if(i>=k-1)
            {
             double it =(double) sum/k;
              maxi = max(maxi , it);
              sum -= nums[i+1-k];
            }
        }
        return maxi;
    }
};