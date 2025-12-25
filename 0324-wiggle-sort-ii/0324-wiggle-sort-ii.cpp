class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n= nums.size();
        vector<int>st = nums;
        sort(st.begin(), st.end());
        int mid = (n-1)/2;
        int  end = n-1;
        for(int i =0 ; i<n ; i++)
        {
         if(i%2==0)
         {
           nums[i]= st[mid];
           mid--;
         }
         else{
            nums[i]= st[end];
            end--;


         }
        }
    }
};