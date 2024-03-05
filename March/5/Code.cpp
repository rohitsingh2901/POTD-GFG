#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int a[], int n) 
    { 
        // Your code here
        vector<int> leftmin(n);
        vector<int> rightmax(n);
        int maxi = INT_MIN;
        for(int i=n-1;i>=0;i--){
            maxi = max(maxi,a[i]);
            rightmax[i]=maxi;
        }
        int mini = INT_MAX;
        for(int i=0;i<n;i++){
            mini = min(mini,a[i]);
            leftmin[i]=mini;
        }
        int ans = -1;
        int i=0,j=0;
        while(i<n && j<n){
            if(rightmax[i]>=leftmin[j]){
                ans = max(i-j,ans);
                i++;
            }
            else{
                j++;
            }
        }
        return ans;
        
    }
};

int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 