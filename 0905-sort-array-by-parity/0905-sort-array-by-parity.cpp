class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        vector<int>res (n, 0);
        int evenI = 0;
        int oddI = n-1;
        for( int i = 0 ; i<n ; i++)
        {
            if(nums[i]%2==0)
            {
                res[evenI]= nums[i];
                evenI++;
            }
            else{
                res[oddI]= nums[i];
                oddI--;
            }
        }
        return res;
    }
};