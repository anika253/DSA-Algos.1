class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int time=0;
        int prevMax=0;
        int n = colors.size();
        for( int i =0 ; i<n ; i++)
        {
            if(i>0 && colors[i]!= colors[i-1])
            {
                prevMax=0;

            }
            time+= min(prevMax, neededTime[i]);
            prevMax= max(neededTime[i], prevMax);
        }
        return time;
        
    }
};