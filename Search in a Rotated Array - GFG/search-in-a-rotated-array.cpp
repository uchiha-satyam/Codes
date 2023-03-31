//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int search(int arr[], int l, int n, int key){
        // l: The starting index
        // h: The ending index, you have to search the key in this range
        
        //complete the function here
        n++;
        int s = 0, e = 0, mid, p=0;
        for(int i=1; i<n; i++)
        {
            if(arr[i]<arr[i-1])
            {
                p = i;
                break;
            }
        }
        e = p-1;
        while(s<=e)
        {
            mid = s + (e-s)/2;
            // cout<<s<<" "<<e<<" "<<mid<<endl;
            if(arr[mid]==key) return mid;
            else if(arr[mid]<key)
            {
                s = mid+1;
            }
            else
            {
                if(s==mid&&s==0)
                {
                    // cout<<"yes"<<endl;
                    s = p;
                    e = n-1;
                    continue;
                }
                e = mid-1;
            }
        }
        return -1;
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