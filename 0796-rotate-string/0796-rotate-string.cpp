class Solution {
public:
    bool rotateString(string s, string goal) {
        int m = s.size();
        int n = goal.size();
        if(m!= n)return false;
        
        string temp = s+s;
        if(temp.find(goal)!= string:: npos)
        {
            return true;
        }
        return false;

    }
};