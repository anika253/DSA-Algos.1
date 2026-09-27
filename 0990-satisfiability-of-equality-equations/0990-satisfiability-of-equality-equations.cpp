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
    bool equationsPossible(vector<string>& equations) {
        int n = equations.size();
        DisjointSet ds(26);
        for(auto eq: equations)
        {
            if(eq[1]=='=')
            {
                int x = eq[0]-'a';
                int y = eq[3]-'a';
                ds.unionByRank(x, y);

            }
          
        }
        for(auto eq: equations)
        {
       if(eq[1]=='!')
            {
                 int x = eq[0]-'a';
                int y = eq[3]-'a';
                int upx= ds.findUPar(x);
                int upy = ds.findUPar(y);
                if(upx==upy)return false;
            }

        }
        return true;
    }
};