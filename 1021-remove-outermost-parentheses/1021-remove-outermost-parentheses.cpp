class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        int depth = 0;
        string temp ="";
        for(int i =0 ; i<n ; i++)
        {
            if(s[i]=='(')
            {
                depth++;
                if(depth >1){
                temp+= s[i];
                }
                
            }
            else if( s[i]==')')
            {
                depth --;
                    if(depth>0){
                temp+=s[i];
            }
            }
            
        }
        return temp;


    }
};