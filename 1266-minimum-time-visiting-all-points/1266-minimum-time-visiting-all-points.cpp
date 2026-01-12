class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n= points.size();
        int dist = 0;

        for( int i = 1 ; i<n ; i++)
        {
            vector<int>a = points[i];
            vector<int>b = points[i-1];
            dist+= max(abs(b[0]-a[0]), abs(b[1]-a[1]));

        }
        return dist;
    }
};