class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color( n , -1);
        queue<int>q;
      for( int i = 0 ; i<n ; i++)
      {
        q.push(i);
        if(color[i]==-1){
        color[i]=0;}
        while(!q.empty())
        {
            auto topo = q.front();
            q.pop();
            for( auto it :graph[topo])
            {
                if(color[it]==-1)
                {
                    q.push(it);
                   color[it]= 1-color[topo];
                }
                else if( color[it]== color[topo])
                {
                 return false;
                }
                
            }
        }
      }
return true;
       
    }
};