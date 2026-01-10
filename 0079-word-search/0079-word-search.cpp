class Solution {
public:
vector<int>dr = {-1 , 0 , 1,0};
vector<int>dc ={0 , -1 , 0 , 1};
bool solve( int m , int n , vector<vector<char>>& board, string word,      vector<vector<int>>&vis, int ind, int i , int j)
{
    if(ind == word.size())
    {
        return true;
    }
    vis[i][j]=1;

    for(int k = 0 ; k<4 ; k++)
    {
        int nr= i+dr[k];
        int nc = j+dc[k];
        if( nr>=0 && nr< m && nc>=0 && nc<n && !vis[nr][nc] && board[nr][nc]==word[ind])
        {
            if( solve( m , n , board, word, vis , ind+1 , nr , nc))
            {
                return true;
            }
        }
    }
    vis[i][j]=0;
return false;


}
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        int ind = 1;
        vector<vector<int>>vis(m , vector<int>(n, 0));
        for(int i= 0 ; i< m ; i++)
        {
            for(int  j = 0 ; j<n ; j++)
            {
                if(board[i][j]==word[0])
                {
                    bool a = solve( m, n , board , word , vis , ind, i , j);
                    if(a)return true;
                }
            }
        }
        return false;

    }
};