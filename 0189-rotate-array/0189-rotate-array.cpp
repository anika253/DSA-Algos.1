class Solution {
public:
void reverseA( vector<int>&nums , int i , int j)
{
    int n = nums.size();
    while(i<j)
    {
        swap( nums[i], nums[j]);
        i++;
        j--;

    }
    
    
    
    
    
}
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if( n==0) return ;
        k = k%n;
        if( k==0) return ;
        reverseA( nums, 0 , n-1);
        reverseA( nums, 0 , k-1);
        reverseA( nums, k, n-1);
    }
};