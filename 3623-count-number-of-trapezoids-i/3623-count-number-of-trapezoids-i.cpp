

class Solution {
public:
const int mod = 1e9+7; 
    int countTrapezoids(vector<vector<int>>& points) {
        int n= points.size();
       
       unordered_map<int, long long>mpp;
       for( auto it: points)
       {
        int u = it[0];
        int v = it[1];
        mpp[v]++;
       } 
  long long  final = 0;
       long long linesTillNow=0;
       for( auto it:mpp)
       {
        int lines = it.second*(it.second-1)/2;
        final = (final+linesTillNow*lines)%mod;
        linesTillNow+= lines;
        
       }
       return final%mod;
        
    }
};