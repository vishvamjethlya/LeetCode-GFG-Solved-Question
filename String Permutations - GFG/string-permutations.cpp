//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
        void solve(string &s, vector<string> &ans, int index){
            if(index == s.size()){
                ans.push_back(s);
                return;
            }
            
            for(int i = index; i < s.size(); i++){
                swap(s[index], s[i]);
                solve(s, ans, index + 1);
                swap(s[index], s[i]);
            }
        }
        
    public:
    vector<string> permutation(string s)
    {
        vector<string> ans;
        int index = 0;
        solve(s, ans, index);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends