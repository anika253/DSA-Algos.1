class Solution {
public:
    bool isPalindrome(string &temp) {
        int i = 0, j = temp.size() - 1;
        while (i < j) {
            if (temp[i] != temp[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    int helper(int i, vector<int>& dp, string& s) {
        int n = s.size();
        if (i == n) return 0;

        if (dp[i] != -1) return dp[i];

        string temp = "";
        int minCost = INT_MAX;

        for (int j = i; j < n; j++) {
            temp += s[j];
            if (isPalindrome(temp)) {
                int cost = 1 + helper(j + 1, dp, s);
                minCost = min(minCost, cost);
            }
        }

        return dp[i] = minCost;  
    }

    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1, -1);
        return helper(0, dp, s) - 1;
    }
};
