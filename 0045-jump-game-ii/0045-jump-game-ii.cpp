class Solution {
public:
    int jump(vector<int>& nums) {
        int  n = nums.size();
        int l = 0;
        int r = 0;
        int cnt = 0;
        int maxJ = 0;
        while( r<n-1)
        {
            for( int i = l ; i<=r ; i++)
            {
            maxJ = max( maxJ , i+nums[i]);
            }
            l= r+1;
            r= maxJ ;
            cnt++;
        }
        return cnt;
    }
};