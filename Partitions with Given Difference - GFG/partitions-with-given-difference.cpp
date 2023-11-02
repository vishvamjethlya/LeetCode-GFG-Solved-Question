//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    int mod = (int)(1e9+7);
    public:
        int solve(int ind, vector<int> &arr, int k, vector<vector<int>> &dp){
            if(ind == 0){
                if(k == 0 && arr[0] == 0) return 2;
                if(k == 0 || arr[0] == k) return 1;
                else return 0;
            }
            
            if(dp[ind][k] != -1) return dp[ind][k];
            
            int notTake = solve(ind-1, arr, k, dp);
            int take = 0;
            if(arr[ind] <= k) take = solve(ind-1, arr, k - arr[ind], dp);
            return dp[ind][k] = (notTake + take) % mod;
        }
    public:
        int findWays(vector<int> &arr, int k, int n){
            vector<vector<int>> dp(n, vector<int>(k+1, -1));
	        return solve(n-1, arr, k, dp) % mod;
        }
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        int totSum = 0;
        for(int i = 0; i < n; i++) totSum += arr[i];
        if((totSum - d) < 0 || (totSum - d)%2) return 0;
        return findWays(arr, (totSum - d)/2, n) % mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends