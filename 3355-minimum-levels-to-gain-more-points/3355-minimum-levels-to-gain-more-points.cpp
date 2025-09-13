class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int n = possible.size();
        vector<int> final(n);
        int lefty = 0;

        
        for (int i = 0; i < n; i++) {
            if (possible[i] == 1)
                lefty += 1;
            else
                lefty -= 1;
            final[i] = lefty;
        }

        int total = final[n - 1]; // total score


        for (int i = 0; i < n - 1; i++) {
            if (2 * final[i] > total) {
                return i + 1; 
            }
        }

        return -1;
    }
};
