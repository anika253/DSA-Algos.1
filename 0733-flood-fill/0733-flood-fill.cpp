class Solution {
public:
vector<int>dr = {-1, 0 , 1, 0};
vector<int>dc={0, 1, 0 , -1};

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>>vis( m, vector<int>(n, 0));
          vector<vector<int>>ans( m, vector<int>(n, 0));
          ans =  image;
          
        queue<pair<int, int>>q;
        q.push({sr, sc});
        vis[sr][sc]=1;
        int orc = image[sr][sc];
        if(color == orc)return image;
        while(!q.empty())
        {
            auto topo = q.front();
            q.pop();
            int row = topo.first;
            int col = topo.second;
            ans[row][col]= color;
            for( int i = 0 ; i<4; i++)
            {
                int nr = row+dr[i];
                int nc = col+dc[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && image[nr][nc]==orc)
                {
                    q.push({nr, nc});
                    vis[nr][nc]=1;
                    ans[nr][nc]=color;

                }
            }

        }
        return ans;

    }
};