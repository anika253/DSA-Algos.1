class Solution {
public:
vector<int>dr= {-1, 0 , 1,0};
vector<int>dc= {0,1,0,-1};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>>dist( m, vector<int>( n, 1e9));
         priority_queue<pair<int , pair<int , int>> , vector<pair<int , pair<int, int>>> , greater<pair<int , pair<int, int>>>>pq;
       dist[0][0]=0;
       pq.push({0 , {0, 0}});
       int currE= 0;
       while(!pq.empty())
       {
        auto topo = pq.top();
         currE = topo.first;
        int row =topo.second.first;
        int col = topo.second.second;
        pq.pop();
        if( row==m-1 && col== n-1) return currE;
        for(int i = 0 ; i<4 ; i++)
        {
            int nr = row+ dr[i];
            int nc = col+dc[i];
            if( nr>=0 && nr< m && nc>=0 && nc<n)
            {
                int newEffort = max( currE ,abs( heights[nr][nc]- heights[row][col]));
                if( dist[nr][nc]> newEffort)
                {
                    dist[nr][nc] = newEffort;
                    pq.push({ newEffort ,{ nr, nc}});
                }
            }
        }
        
         

       }
       return currE;
       
    }
};