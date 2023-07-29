//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    unordered_map<char, int> map;
	    int k = pat.size();
	    for(int i = 0; i < k; i++){
	        map[pat[i]]++;
	    }
	    int count = map.size();
	    int ans = 0;
	    int i = 0, j = 0;
	    while(j < txt.size()){
	        if(map.find(txt[j]) != map.end()){
	            map[txt[j]]--;
	            if(map[txt[j]] == 0) count--;
	        }
	        if(j - i + 1 < k){
	            j++;
	        }
	        else if(j - i + 1 == k){
	            if(count == 0){
	                ans++;
	            }
	            if(map.find(txt[i]) != map.end()){
	                if(map[txt[i]] == 0) count++;
	                map[txt[i]]++;
	            }
	            i++;
	            j++;
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends