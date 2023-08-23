//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
    public:
        int firstOccur(int arr[], int target, int n){
            int s = 0, e = n - 1;
            int ans = -1;
            while(s <= e){
                int mid = s - (s - e)/2;
                
                if(arr[mid] == target){
                    ans = mid;
                    e = mid - 1;
                }
                else if(arr[mid] > target) e = mid - 1;
                else s = mid + 1;
            }
            return ans;
        }
        
        int lastOccur(int arr[], int target, int n){
            int s = 0, e = n - 1;
            int ans = -1;
            while(s <= e){
                int mid = s - (s - e)/2;
                
                if(arr[mid] == target){
                    ans = mid;
                    s = mid + 1;
                }
                else if(arr[mid] > target) e = mid - 1;
                else s = mid + 1;
            }
            return ans;
        }
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    int ans = 0;
        int first = firstOccur(arr, x, n);
        if(first == -1) return ans;
        int last = lastOccur(arr, x, n);
        ans = last - first + 1;
        return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends