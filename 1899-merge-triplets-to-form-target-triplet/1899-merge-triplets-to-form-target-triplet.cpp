class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& t) {
        vector<int>res(3, 0);
       
        for( auto it: triplets)
        {
            if(it[0]<= t[0] && it[1]<= t[1] && it[2]<= t[2])
            {
                res = {max(res[0], it[0]),max(res[1], it[1]), max(res[2], it[2]) };
            }
            if(res==t)
            {
                return true;
            }
        }
        return false;

    }
};