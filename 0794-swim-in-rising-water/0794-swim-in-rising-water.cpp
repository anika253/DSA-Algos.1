#include <vector>
using namespace std;

class Solution {
public:
    bool reachableOrnot(int T, vector<vector<int>>& grid, int n, int i, int j, vector<vector<bool>>& vis) {
        if (i == n - 1 && j == n - 1) {
            return true;  // Reached the destination
        }
        
        vis[i][j] = true;
        
        vector<int> dr = {-1, 0, 1, 0};  // Directions for row
        vector<int> dc = {0, 1, 0, -1};  // Directions for column
        
        for (int dir = 0; dir < 4; dir++) {
            int nr = i + dr[dir];  // New row
            int nc = j + dc[dir];  // New column
            
            if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                !vis[nr][nc] && grid[nr][nc] <= T) {
                
                if (reachableOrnot(T, grid, n, nr, nc, vis)) {
                    return true;  // Found a valid path
                }
            }
        }
        
        return false;  // No valid path found
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int low = 0;
        int high = n * n - 1;
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            vector<vector<bool>> vis(n, vector<bool>(n, false));  // Corrected initialization
            
            if (grid[0][0] <= mid && reachableOrnot(mid, grid, n, 0, 0, vis)) {
                high = mid;  // Try a smaller time
            } else {
                low = mid + 1;  // Increase time
            }
        }
        
        return low;  // Minimum time required to swim to (n-1, n-1)
    }
};
