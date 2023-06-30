//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int isDivisible(string s){
	    //complete the function here
	    int c = 0;
	    for(int i=0; i<s.length(); i++)
	    {
	        if(i%2)
	        c -= (s[i]-'0');
	        else
	        c += (s[i]-'0');
	    }
	    if(c%3) return false;
	    return true;
	}
};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}


// } Driver Code Ends