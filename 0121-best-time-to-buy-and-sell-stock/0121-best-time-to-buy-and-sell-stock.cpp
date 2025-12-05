class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int cp = INT_MAX;
        int profir =  INT_MIN;
        for(int i = 0 ; i<n; i++)
        {
            cp = min( cp , prices[i]);
            profir = max(profir , prices[i]-cp);
        }
        return profir;
    }
};