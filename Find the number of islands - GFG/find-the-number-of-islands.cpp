//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
        void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> grid){
            vis[row][col] = 1;
            queue<pair<int, int>> q;
            q.push({row, col});
            int n = grid.size();
            int m = grid[0].size();
            while(!q.empty()){
                int currRow = q.front().first;
                int currCol = q.front().second;
                q.pop();
                
                for(int delRow = -1; delRow <= 1; delRow++){
                    for(int delCol = -1; delCol <= 1; delCol++){
                        int nrow = currRow + delRow;
                        int ncol = currCol + delCol;
                        
                        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                        && vis[nrow][ncol] != 1 && grid[nrow][ncol] == '1'){
                            vis[nrow][ncol] = 1;
                            q.push({nrow, ncol});
                        }
                    }
                }
            }
        }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                if(!vis[row][col] && grid[row][col] == '1'){
                    vis[row][col] = 1;
                    dfs(row, col, vis, grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends