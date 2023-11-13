//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int findPivot(int arr[], int start, int end){
        while (start <= end){
            int mid = start + (end - start) / 2;
            //4 cases
            if(mid < end && arr[mid] > arr[mid + 1]){
                return mid;
            }
            else if(mid > start && arr[mid] < arr[mid - 1]){
                return mid -1;
            }
            else if (arr[mid] <= arr[start]){
                end = mid - 1;
            }
            else if (arr[mid] > arr[start]){
                start = mid + 1;
            }
        }
        return -1;
    }
    public:
    int binarySearch(int A[], int target, int start, int end){
        
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (target < A[mid]) {
                end = mid - 1;
            }else if (target > A[mid]) {
                start = mid + 1;
            }else {
                return mid;
            }
        }
        return -1;
    }
    public:
    int search(int nums[], int l, int h, int target){
        int pivot = findPivot(nums, l, h);
        if (pivot == -1){
            // normal binary search
            return binarySearch(nums, target , 0, h);
        }
        if (nums[pivot] == target){
            return pivot;
        }
        else if (nums[0] <= target){
            return binarySearch(nums, target, 0, pivot - 1);
        }
        else {
            return binarySearch(nums, target, pivot + 1, h);
        }
    }
};

//{ Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}
// } Driver Code Ends