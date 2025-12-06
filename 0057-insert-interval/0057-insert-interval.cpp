class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& inte, vector<int>& newInterval) {
        int n= inte.size();
        vector<vector<int>>final;
        int i =0 ; 
        while(i<n && newInterval[0]>inte[i][1])
        {  final.push_back(inte[i]);
            i++;

        }
       while( i<n && inte[i][0]<= newInterval[1])
        {
            newInterval[0]= min( newInterval[0], inte[i][0]);
            newInterval[1]= max( newInterval[1], inte[i][1]);
            i++;
        }
         final.push_back( newInterval);
        while( i<n && newInterval[1]< inte[i][0])
        {
            final.push_back(inte[i]);
            i++;

        }


return final;


    }
};