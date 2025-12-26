class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int>yes(n+1, 0);
        vector<int>no(n+1, 0);
        
        int y = 0;
        int n1= 0;
        for(int i = n-1; i>=0 ; i--)
        {
            if(customers[i]=='Y')
            {
                y++;}
                yes[i]=y;
            
        }
      

        for(int i =0 ; i<n ; i++)
        {
            if(customers[i]=='N')
            {
                n1++;}
                no[i+1]=n1;
            

        }
      

        vector<int>ans(n+1, 0);
      int final = INT_MAX;
      int bh = 0;
        for(int i = 0 ; i<=n ; i++)
        {
            ans[i]= yes[i]+no[i];
           if(ans[i]<final)
           {
            final = min(final , ans[i]);
            bh = i;
           }

            
        }
        return bh;
    }
};