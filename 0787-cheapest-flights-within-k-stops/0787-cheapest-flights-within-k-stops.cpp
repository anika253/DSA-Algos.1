class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int , int>>>adj(n);
        for( auto it : flights)
        {
            int s = it[0];
            int d = it[1];
            int di = it[2];
            adj[s].push_back({d, di});
        }
        queue<pair<int , pair<int, int>>>q;
        vector<int>dist( n , 1e9);
        dist[src]=0;
        q.push({0 , {src, 0}});
        int st = 0;

       while(!q.empty())
       {
        auto topo = q.front();
       st = topo.first;
        q.pop();
        int node =topo.second.first;
        int disty = topo.second.second;
        if(st>k)break;
        for( auto it: adj[node])
        {
            int nn = it.first;
            int dist2 = it.second;
            if(disty+dist2<=dist[nn] && st<=k)
            {
                dist[nn]= disty+ dist2;

                q.push({st+1, {nn, dist[nn]}});

            }

        }
        
       }
       if(dist[dst]==1e9)return -1;

       return dist[dst];
       

            
                    

    }
};