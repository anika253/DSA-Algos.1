class Solution {
public:
    void solve(string &s, int i, vector<string> &res) {
        // Base case: reached end of string
        if (i == s.size()) {
            res.push_back(s);
            return;
        }

        
        if (isalpha(s[i])) {
            // Keep as is
            solve(s, i + 1, res);

            s[i] = islower(s[i]) ? toupper(s[i]) : tolower(s[i]);
            solve(s, i + 1, res);

       
            s[i] = islower(s[i]) ? toupper(s[i]) : tolower(s[i]);
        } else {
            // If it's a digit, skip to next
            solve(s, i + 1, res);
        }
    }

    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        solve(s, 0, res);
        return res;
    }
};
