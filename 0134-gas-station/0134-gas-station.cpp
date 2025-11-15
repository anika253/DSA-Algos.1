class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int m = cost.size();
       if(accumulate(gas.begin(), gas.end(),0)< accumulate(cost.begin(), cost.end(),0))
        {
            return -1;

        }
      
        int res_I = 0;
        int total = 0;
        for( int i =0 ; i<n ; i++)
        {
            total += gas[i]- cost[i];
            if(total < 0)
            {
                res_I = i+1;
                total = 0;

            }

        }
        return res_I;


    }
};