//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
        int getLength(struct node* head){
            int ans = 0;
            struct node* temp = head;
            while(temp != NULL){
                ans++;
                temp = temp -> next;
            }
            return ans;
        }
    
    public:
        struct node* kReverse(struct node* head, int k, int length){
            if(head == NULL || head -> next == NULL || k == 1) return head;
            
            struct node* prev = NULL;
            struct node* curr = head;
            struct node* forward = NULL;
            
            int count = 0;
            
            while(count < k && curr != NULL){
                forward = curr -> next;
                curr -> next = prev;
                prev = curr;
                curr = forward;
                count++;
            }
            
            if(forward != NULL){
                head -> next = kReverse(forward, k, (length-k));
            }
            
            return prev;
        }
    public:
    struct node *reverse (struct node *head, int k)
    { 
        int len = getLength(head);
        return kReverse(head, k, len);
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends