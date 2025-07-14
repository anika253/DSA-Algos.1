#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
     int n= val.size();
     vector<vector<int>>dp(n, vector<int>(capacity+1,0));
 
     
             for(int j = wt[0]; j<=capacity; j++)
             {
                 dp[0][j]= ((j/wt[0])*val[0]);
             }
     
     for(int i =1 ; i<n ; i++)
     {
         for( int j = 0; j<= capacity; j++)
         {
             int nt= dp[i-1][j];
             int t= -1e9;
             if(wt[i]<=j)
             {
                 t= val[i]+dp[i][j-wt[i]];
             }
             
             dp[i][j]= max(t, nt);
             
             
         }
     }
     
     
     
     return dp[n-1][capacity]; 
     
 } 

int main() {
	vector<int>val={5,11, 13};
	vector<int>wt= {2,4,6};
	int capacity= 10;
	int ans = knapSack(val, wt,capacity);
	cout << "max value is"<<" "<< ans<< endl;

}
