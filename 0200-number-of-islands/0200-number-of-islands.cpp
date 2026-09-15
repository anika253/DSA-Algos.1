class Solution {
public:
vector<int>dr={-1,0,1,0};
vector<int>dc={0,1,0,-1};
void bfs(vector<vector<char>>& grid ,vector<vector<int>>&vis, queue<pair<int,int>>&q , int m , int n, int i , int j )
{
    q.push({i, j});
    vis[i][j]=1;
    while(!q.empty())
    {
        auto topo = q.front();
        q.pop();
        int row = topo.first;
        int col= topo.second;
         for(int i = 0; i<4; i++)
         {
            int nr = row+dr[i];
            int nc = col+dc[i];
            if(nr>=0 && nr< m && nc>=0 && nc<n && !vis[nr][nc] && grid[nr][nc]=='1')
            {
                q.push({nr, nc});
                vis[nr][nc]=1;
            }
         }
    }

}
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>vis(m, vector<int>(n,0));
        queue<pair<int,int>>q;
        int cnt = 0;
        for(int i=0 ; i<m ; i++)
        {
            for(int j =0 ; j<n; j++)
            {
                if(!vis[i][j] && grid[i][j]=='1')
                {
                    cnt++;
                    bfs(grid , vis , q, m , n, i , j  );
                }
            }
        }
        return cnt;
    }
};