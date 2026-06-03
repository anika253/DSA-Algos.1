class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        vector<int>res(n , 0);
         int evenI = 0;
          int oddI = 1;
            
        for( int i = 0; i<n ; i++)
        {
            if(nums[i]%2==0)
            {
                res[evenI]= nums[i];
                evenI+=2;
            }
            else{
                res[oddI]= nums[i];
                oddI+=2;
            }
           
        }
        return res;
    }
};