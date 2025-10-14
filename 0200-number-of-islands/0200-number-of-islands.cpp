class Solution {
public:
vector<int>dr = {-1,0,1,0};
vector<int>dc= {0,1,0,-1};
void bfs( int i , int j  , int m , int n ,vector<vector<char>>& grid, vector<vector<int>>&vis,  queue<pair<int, int>>&q)
{
  q.push({i, j});
  vis[i][j]=1;
    while(!q.empty())
    {
        auto topo = q.front();
        q.pop();
        int row = topo.first;
        int col = topo.second;
        for( int i = 0 ; i<4 ; i++)
        {
            int ni = row+dr[i];
            int nj = col+dc[i];
            if(ni>=0 && ni<m && nj>=0 && nj<n && !vis[ni][nj] && grid[ni][nj]=='1')
            {
                q.push({ni , nj});
                vis[ni][nj]=1;
            }
            
        }
    }

}
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        vector<vector<int>>vis(m , vector<int>(n, 0));
        queue<pair<int, int>>q;
        for( int i = 0 ; i<m ; i++)
        {
            for( int j = 0 ; j<n ; j++)
           {
            if(vis[i][j]==0 && grid[i][j]=='1')
            {
                cnt++;
                bfs( i , j, m ,n ,grid, vis,   q);
            }
           }
        }
        return cnt;
    }
};