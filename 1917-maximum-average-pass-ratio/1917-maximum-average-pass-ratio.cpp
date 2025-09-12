class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n= classes.size();
        priority_queue<pair<double, int>>pq;
        double final =0.0;
        double result = 0.0;

        for(int i =0 ; i< n ; i++)
        {
            double cpr = (double)classes[i][0]/ classes[i][1];
         double npr = ((double)classes[i][0]+1) /( classes[i][1]+1);
         double delta = npr - cpr;
         pq.push({delta,i});


        }
        while(extraStudents--)
        {
             auto topo = pq.top();
             pq.pop();
             double delta = topo.first;
             int idx = topo.second;

          classes[idx][0]++;
          classes[idx][1]++;
          double cpr = (double)classes[idx][0]/ classes[idx][1];
         double npr = ((double)classes[idx][0]+1 )/( classes[idx][1]+1);
         delta = npr - cpr;
         pq.push({delta,idx});




        }
        for( int i = 0 ; i< n ; i++)
        {
            final+= (double)classes[i][0]/classes[i][1];

        }
        
        return final/n;

        
    }
};