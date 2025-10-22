class Solution {
public:
    int n;
    int dp[1 << 15]; 

    int dfs(int pos, int mask) {
        if (pos > n) return 1; 
        if (dp[mask] != -1) return dp[mask];

        int ways = 0;
        for (int num = 1; num <= n; num++) {
            if ((mask & (1 << (num - 1))) == 0) { 
                if (num % pos == 0 || pos % num == 0) {
                    ways += dfs(pos + 1, mask | (1 << (num - 1)));
                }
            }
        }

        return dp[mask] = ways;
    }

    int countArrangement(int n) {
        this->n = n;
        memset(dp, -1, sizeof(dp));
        return dfs(1, 0); 
    }
};
