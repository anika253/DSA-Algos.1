class Solution {
public:
int leftmostOcc( vector<int>& nums, int target )
{ int s =0;
int n = nums.size();
int e= n-1;
int mid = s+(e-s)/2;
int ans = -1;

while(s<=e)
   
{    if  (nums[mid]== target )
{
    ans = mid;
    e= mid-1;

}
else if (nums[mid]>target )
{
e = mid-1;
}
else if (nums[mid]< target )
{
    s = mid+1;

}

mid = s+(e-s)/2;}
return ans;








}
int lastmostOcc( vector<int>& nums, int target )
{ int s =0;
int n = nums.size();
int e= n-1;
int mid = s+(e-s)/2;
int ans = -1;

while(s<=e)
{    if  (nums[mid]== target )
{
    ans = mid;
    s = mid+1;


}
else if (nums[mid]>target )
{
e = mid-1;
}
else if (nums[mid]< target )
{
    s = mid+1;

}

mid = s+(e-s)/2;}
return ans;







}















    vector<int> searchRange(vector<int>& nums, int target) {  
        return { leftmostOcc( nums,target),lastmostOcc(nums,target)};
    }






        
    
};