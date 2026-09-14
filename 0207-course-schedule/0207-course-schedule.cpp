class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& p) {
        int n = numCourses;
        vector<vector<int>>adj(n);
        vector<int>ans;
        queue<int>q;
        vector<int>in(n, 0);

        for(auto it:p)
        {
            int u = it[0];
            int v= it[1];
            adj[u].push_back(v);
            in[v]++;
          

        }
        for(int i =0 ; i<in.size(); i++)
        {
              if(in[i]==0)
              {
                q.push(i);
                
              }
        }

        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            ans.push_back(it);
          
             for(auto x: adj[it])
             {
                in[x]--;
                if(in[x]==0)
                {
                    q.push(x);
                }
                
             }
        }
        if(ans.size()==n)return true;
        return false;
    }
};