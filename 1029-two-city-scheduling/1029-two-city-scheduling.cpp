class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
int n = costs.size()/2;
int cityA =0;
for( int i = 0; i<costs.size(); i++)
{
    cityA+=costs[i][0];
}
int cityB = 0;
vector<int>refund(2*n, 0);
for( int i = 0; i<costs.size(); i++)
{
  refund[i]= costs[i][1]-costs[i][0];
}
sort(refund.begin(), refund.end());
for( int i = 0 ; i<n ; i++)
{
    cityB+=refund[i];
}
int final = cityA+cityB;
return final;

    }
};