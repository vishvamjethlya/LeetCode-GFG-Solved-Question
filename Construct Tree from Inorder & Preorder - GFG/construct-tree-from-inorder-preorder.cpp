//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    int findPosition(int element, int in[],int inOrderStart, int inOrderEnd, int n){
        for(int i = inOrderStart; i<= inOrderEnd; i++){
            if(in[i] == element) return i;
        }
        return -1;
    }
    Node* func(int in[],int pre[], int &index, int inOrderStart, int inOrderEnd, int n){
        if(index >= n || inOrderStart > inOrderEnd) return NULL;
        
        int element = pre[index++];
        Node* root = new Node(element);
        int posi = findPosition(element, in, inOrderStart, inOrderEnd, n);
        
        root -> left =  func(in, pre, index, inOrderStart, posi - 1, n);
        root -> right = func(in, pre, index, posi + 1, inOrderEnd, n);
        
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        int preOrderIndex = 0;
        Node* ans = func(in, pre, preOrderIndex, 0, n - 1, n);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends