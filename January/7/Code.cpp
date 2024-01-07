#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
        bool check(int mid, int arr[], int N, int K) {
            int tot = 1, sum = 0;
            for (int i = 0; i < N; i++) {
                sum += arr[i];
                if (sum > mid) {
                    sum = arr[i];
                    tot++;
                }
            }
            return tot <= K;
        }

        int splitArray(int arr[], int N, int K) {
            // Finding the lowest possible maximum sum
            int low = *max_element(arr, arr + N); // Initializing 'low' with the maximum element in the array
            // Finding the highest possible maximum sum
            int high = 0;
            for (int i = 0; i < N; i++) {
                high += arr[i]; // Summing up all elements in the array to find the upper limit
            }
            int ans = 0; // Variable to store the answer
            
            // Binary search to find the minimum possible maximum subarray sum
            while (low <= high) {
                int mid = low + (high - low) / 2; // Calculating the middle value
                if (check(mid, arr, N, K)) { // Checking if 'mid' is a valid candidate for the minimum maximum sum
                    ans = mid; // Updating 'ans' if 'mid' is a valid solution
                    high = mid - 1; // Moving towards the left to explore smaller 'mid' values
                } else {
                    low = mid + 1; // Moving towards the right to explore larger 'mid' values
                }
            }
            return ans; // Returning the final minimum maximum subarray sum achievable
        }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
