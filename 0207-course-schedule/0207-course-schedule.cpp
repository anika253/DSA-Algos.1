class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& p) {
           int n  = numCourses;
        vector<vector<int>>adj(n);
        vector<int>indegree(n, 0);
        for(auto it: p)
        {
            int u =it[0];
            int v = it[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int>q;
        for( int i = 0 ;i<n; i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty())
        {
            auto topo = q.front();
            q.pop();
            ans.push_back(topo);
            for( auto it: adj[topo])
            {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    q.push(it);
                }
            }
        }
        if(ans.size()==numCourses)
        {
            return true;
        }
        return false;
       
    }
};