class DisjointSet{
    public:
    vector<int>rank, parent;
    DisjointSet(int n)
    {
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for(int i= 0 ; i<n ; i++)
        {
            parent[i]=i;
        }
    }
    int findUPar(int node)
    {
        if(parent[node]==node)
        {
            return node;
        }
        return parent[node]= findUPar(parent[node]);
    }
    void unionByRank( int  u , int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(rank[ulp_u]> rank[ulp_v])
        {
            parent[ulp_v]= ulp_u;
        }
        else if(rank[ulp_u]< rank[ulp_v])
        {
            parent[ulp_u]= ulp_v;
        }
        else if(rank[ulp_u]==rank[ulp_v])
        {
            parent[ulp_u]= ulp_v;
            rank[ulp_v]++;
        }
    }
    
};



class Solution {
public:

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet ds(n);
        vector<int>ans;
        for(auto it:edges)
        {
            int u = it[0];
            int v = it[1];
            int ulp_u = ds.findUPar(u);
            int ulp_v= ds.findUPar(v);
            if(ulp_u ==ulp_v)
            {
                ans.push_back(u);
                ans.push_back(v);
            }
            else{
                ds.unionByRank(u , v);
            }

        }
        return ans;
    }
};