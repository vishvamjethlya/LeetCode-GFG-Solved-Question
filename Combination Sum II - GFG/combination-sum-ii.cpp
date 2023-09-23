//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    public:
        void solve(int ind, vector<int> &arr, int target, vector<vector<int>> &ans, vector<int> output){
            if(target == 0){
                ans.push_back(output);
                return;
            }
            
            for(int i = ind; i < arr.size(); i++){
                if(i != ind && arr[i] == arr[i-1]) continue;
                if(arr[i] > target) break;
                output.push_back(arr[i]);
                solve(i + 1, arr, target - arr[i], ans, output);
                output.pop_back();
            }
        }
  public:
    vector<vector<int>> combinationSum2(vector<int> &arr, int target) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        vector<int> output;
        solve(0, arr, target, ans, output);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> candidates(n);
        for (int i = 0; i < n; ++i) {
            cin >> candidates[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;

        vector<vector<int>> comb = obj.combinationSum2(candidates, k);
        sort(comb.begin(), comb.end());
        cout << "[ ";
        for (int i = 0; i < comb.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < comb[i].size(); j++) {
                cout << comb[i][j] << " ";
            }
            cout << "]";
        }
        cout << " ]\n";

        // cout << "\n~\n";
    }
    fclose(stdout);
    return 0;
}

// } Driver Code Ends