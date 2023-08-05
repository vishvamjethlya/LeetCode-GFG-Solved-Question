//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        unordered_map<char, int> map;
        int n = s.size();
        int longest = -1;
        int left = 0, right = 0;
        while(right < n){
            map[s[right]]++;
            if(map.size() == k){
                longest = max(longest, right - left + 1);
            }
            else if(map.size() > k){
                while(map.size() > k){
                    map[s[left]]--;
                    if(map[s[left]] == 0){
                        map.erase(s[left]);
                    }
                    left++;
                }
            }
            right++;
        }
        return longest;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends