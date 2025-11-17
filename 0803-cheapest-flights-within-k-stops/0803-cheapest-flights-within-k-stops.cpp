class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    
        vector<vector<pair<int , int>>>adj(n);
        for( auto it : flights)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v, wt});
            

      }
      queue<pair<int , pair<int , int>>>q;
      vector<int>dist( n , 1e9);
      dist[0]=0;
      q.push({0, {src , 0}});
      while(!q.empty())
      {
        auto topo = q.front();
        q.pop();
        int steps = topo.first;
        int node = topo.second.first;
        int disty = topo.second.second;
        if(steps>k)break;
        for( auto it: adj[node])
        {
            int nn = it.first;
            int ndist = it.second;
            if(ndist+disty < dist[nn] && steps<=k)
            {
               dist[nn]= ndist+disty;
               q.push({steps+1, {nn ,ndist}});
            }
        }
      }
      if(dist[dst]==1e9) return -1;
      return dist[dst];

    }
};