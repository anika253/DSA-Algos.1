#include <iostream>
#include <vector>   
#include <string>
using namespace std;
void printlcs(string s1, string s2, string &temp)
{   int n= s1.size();
    int m = s2.size();
    
    vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
    for(int i =1 ; i<=n ; i++)
    {
        for( int j = 1; j<=m ; j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j]= 1+dp[i-1][j-1];
            }
            else{
                dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
                
            }
        }
    }
    int i= n;
    int j= m;
   
    while(i>0 && j>0)
    {
         if(s1[i-1]==s2[j-1])
         {
             temp+= s1[i-1];
             i--;
             j--;
         }
         else if(dp[i-1][j]> dp[i][j-1])
         {
             i--;
         }
         
       
       else{
           j--;
       }
  
}
reverse(temp.begin(), temp.end());
}

int main() {
	string s1 = "abcde";
	string s2 = "ace";
	string temp="";
 printlcs(s1, s2, temp);
 cout << temp<< endl;
}
