class Solution {
public:
vector<int>dr= {-1,0,1,0};
vector<int>dc= {0 , 1, 0 ,-1};
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cntF=0;
        int cnt = 0;
        int time = 0;
        vector<vector<int>>vis( m , vector<int>(n, 0));
        queue<pair<int , pair<int, int>>>q;
        for(int i = 0; i<m ; i++)
        {
            for( int j = 0; j<n ; j++)
            {
                if(grid[i][j]==1)
                {
                    cntF++;
                    
                }
            
            else if(grid[i][j]==2)
            {
                q.push({0, {i, j}});
                vis[i][j]=1;
            }
        }
        }
             while(!q.empty())
             {
                auto topo = q.front();
                q.pop();
                time = topo.first;
                int r = topo.second.first;
                int c = topo.second.second;
                for(int x =0 ; x<4; x++)
                {
                    int nr = r+dr[x];
                    int nc = c+dc[x];
                  if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && grid[nr][nc]==1)
                  {
                    q.push({time+1, {nr, nc}});
                    vis[nr][nc]=1;
                      cnt++;
                  }


                }

             
             }
             if(cnt!=cntF)return -1;
        return time;
    }
};