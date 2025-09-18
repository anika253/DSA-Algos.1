class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
     
        vector<vector<pair<int, int>>>adj(n);
        for( auto it: flights)
        {
            int u = it[0];
            int v = it[1];
            int w  = it[2];
            adj[u].push_back({v, w});
        }
        vector<int>dist( n, 1e9);
        queue<pair<int , pair<int , int>>>q;// {stops , {node , dist}};
        q.push({0 , {src, 0}});
        while(!q.empty())
        {
            auto topo = q.front();
            int steps =topo.first;
            int node = topo.second.first;
            int disti = topo.second.second;
            q.pop();
            if(steps>k) break;
            for( auto it:adj[node])
            {
                int nn = it.first;
                int disty = it.second;
                if( disti+disty< dist[nn] && steps<=k)
                {
                dist[nn]= disti+disty;
                q.push({steps+1,{nn, dist[nn]}});
                }
            }
        }
        if( dist[dst]==1e9)return -1;
        return dist[dst];

    }
};