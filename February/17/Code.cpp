
#include <bits/stdc++.h>
using namespace std;



class Solution{
    public:
    bool isMaxHeap(int arr[], int n)
    {
        // Your code goes here
        int child = 1;
        for(int par = 0;par<n;par++){
            if(child<n && arr[child]>arr[par]) return 0;
            if(child+1<n && arr[child+1]>arr[par]) return 0;
            child+=2;
        }
        return 1;
    }
};


int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
       int n;
       cin >> n;
       int a[4*n]={0};
       for(int i =0;i<n;i++){
           cin >> a[i];
       }
       Solution ob;
       cout<<ob.isMaxHeap(a, n)<<endl;
        
    }
    return 0;
}
