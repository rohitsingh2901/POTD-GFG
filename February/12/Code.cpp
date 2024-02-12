//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

//User function Template for C++

class Solution{
public:
    int MOD = 1e9 + 7;

    long long sequence(int n) {
        long long ans = 0;
        
        for (int i = 1; i <= n; i++) {
            long long val = 1;
            int num = (i - 1) * i / 2 + 1;  // Start number for the current term
            for (int j = 0; j < i; j++) {
                val = (val * num) % MOD;
                num++;
            }
            ans = (ans + val) % MOD;
        }
        
        return ans;
    }

};


int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}