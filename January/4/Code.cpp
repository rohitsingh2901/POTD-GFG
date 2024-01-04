#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int singleElement(int arr[], int N) {
        int res = 0;
        for (int i = 0; i < 32; i++) { // Iterate through each bit position (32 bits for integers)
            int ans = 0;
            for (int j = 0; j < N; j++) {
                // Check if the bit at position i is set for the j-th element
                if ((arr[j] & (1 << i)) != 0) {
                    ans++; // Increment count if the bit is set
                }
            }
            if (ans % 3 == 1) {
                // If the count modulo 3 is 1, set the bit in the result
                res += (1 << i); // Set the bit in the result for that position
            }
        }
        return res; // Return the final result containing the single occurring element
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.singleElement(arr,N);
        cout<<"\n";
    }
    return 0;
}