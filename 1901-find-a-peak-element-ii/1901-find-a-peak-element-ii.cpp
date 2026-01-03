class Solution {
public:
int find(vector<vector<int>>& mat , int mid)
{
    int maxi = -1;
   int ans = 0;
    for( int i =0 ; i<mat.size(); i++)
    {
            if(mat[i][mid]>maxi)
            {
                maxi = mat[i][mid];
                ans = i;
            }
    }
    return ans;
}
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    int low = 0;
    int high = m-1;
    while(low<= high)
    {
        int mid = (low+high)/2;
        int maxri = find(mat ,  mid);
     int left =-1;
     int right = -1;
     if(mid-1 >= 0)
     {
        left = mat[maxri][mid-1];
     }
     if(mid+1< m)
     {
        right = mat[maxri][mid+1];
     }
     if(mat[maxri][mid]>left && mat[maxri][mid]>right)
     {
        return {maxri ,mid};
     }
     else if(mat[maxri][mid]<left)
     {
        high = mid-1;
     }
     else{
        low = mid+1;
     }
    }
    return {-1, -1};

    }
};