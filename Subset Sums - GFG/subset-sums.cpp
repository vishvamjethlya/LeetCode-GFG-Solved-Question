//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
    public:
        void solve(int index, vector<int> &arr, vector<int> &ans, int sum){
            if(index >= arr.size()){
                ans.push_back(sum);
                return;
            }
            
            int ele = arr[index];
            sum += ele;
            solve(index + 1, arr, ans, sum);
            sum -= ele;
            solve(index + 1, arr, ans, sum);
        }
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        int sum = 0;
        int index = 0;
        solve(index, arr, ans, sum);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends