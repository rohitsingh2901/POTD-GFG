#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int numberSequence(int m, int n){
        // code here
        if(m < n) return 0;    // If m is less than n, it's not possible to form a sequence
        if(n == 0) return 1;    // If n is 0, there is only one way to form a sequence (empty sequence)
        
        return numberSequence(m - 1, n) + numberSequence(m / 2, n - 1);
        // Recursively calculate the number of sequences:
        // 1. If we exclude the current maximum value m (m - 1), and keep the same length n.
        // 2. If we include the current maximum value m, reduce the length by 1 (n - 1).

        // The total number of sequences is the sum of the above two cases.
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int m, n;
        cin>>m>>n;
        
        Solution ob;
        cout<<ob.numberSequence(m, n)<<endl;
    }
    return 0;
}