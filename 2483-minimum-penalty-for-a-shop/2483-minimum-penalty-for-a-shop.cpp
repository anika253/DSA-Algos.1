class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();

        vector<int> yes(n + 1, 0);  
        vector<int> no(n + 1, 0);  

        
        for (int i = n - 1; i >= 0; i--) {
            yes[i] = yes[i + 1] + (customers[i] == 'Y');
        }

       
        for (int i = 0; i < n; i++) {
            no[i + 1] = no[i] + (customers[i] == 'N');
        }

        int minPenalty = INT_MAX;
        int ans = 0;

        for (int i = 0; i <= n; i++) {
            int penalty = no[i] + yes[i];
            if (penalty < minPenalty) {
                minPenalty = penalty;
                ans = i;
            }
        }

        return ans;
    }
};
