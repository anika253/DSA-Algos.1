class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<int>q;
        vector<int>clr(n , -1);
        for( int i = 0 ; i<n ; i++){
            if(clr[i]==-1){
        clr[i]=0;}
        q.push(i);

        while(!q.empty())
        {
            auto topo = q.front();
            q.pop();
            for(auto i: graph[topo])
            {
                 if(clr[i]==-1)
                 {
                    q.push(i);
                    clr[i]= 1-clr[topo];

                 }
                 else if(clr[i]==clr[topo])
                 {
                    return false;
                 }
            }
        }
        }
return true;

    }
};