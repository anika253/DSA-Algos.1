class Solution {
public:
    vector<int> roww = {1, -1, 0, 0};
    vector<int> coll = {0, 0, -1, 1};
    int dfs( int i , int j ,vector<vector<int>>& grid, int m , int n)
    {
   if(i<0 || j<0 || i>= m || j>= n || grid[i][j]==0)return 0;
   int curr= grid[i][j];
   grid[i][j]=0;
   int localG = curr;
   for( int xx =0 ; xx<4 ; xx++)
   {
    int newR = i+roww[xx];
    int newC= j+coll[xx];
    localG = max(localG, curr+dfs(newR, newC, grid , m, n));
   }
    grid[i][j]=curr;
    return localG;

    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxG=0;
        for( int i = 0 ; i<m ; i++)
        {
            for( int j =0 ; j<n ; j++)
            {
                if(grid[i][j]!=0)
                {
                  maxG = max(maxG, dfs(i , j , grid, m,n));
                }
            }
        }
       return maxG;
    }
};