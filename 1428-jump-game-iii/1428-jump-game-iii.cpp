class Solution {
public:
bool helper(vector<int>& arr, int  i ,  vector<bool>&vis)
{
    if( i <0 || i>=arr.size() || vis[i])
    {
        return false;
    }
    vis[i]= true;
    if(arr[i]==0)
    {
        return true;
    }
    int l = helper( arr, i-arr[i], vis);
    int r = helper( arr, i+arr[i], vis);
    return l||r;
    
}


    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool>vis( n , 0);
        return helper( arr, start , vis);
    }
};