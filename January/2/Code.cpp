#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long int maxSumWithK(long long int a[], long long int n, long long int k) {
        long long int sum = 0; // Change sum to long long int

        // Calculate sum of first k elements
        for (int i = 0; i < k; i++) {
            sum += a[i];
        }
        long long int maxsum = sum;
        long long int p = maxsum;

        // Iterate through the array using sliding window technique
        for (int i = k; i < n; i++) {
            // Update the current sum by removing the leftmost element of the window
            // and adding the rightmost element of the window
            sum = sum + a[i] - a[i - k];

            // Update 'p' by choosing the maximum between the sum of the current element
            // and the previous 'p' plus the current element
            p = std::max(p + a[i], sum);

            // Update 'maxsum' to keep track of the maximum sum found so far
            maxsum = std::max(maxsum, p);
        }
        return maxsum;
    }
};

int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        Solution ob;
        cout << ob.maxSumWithK(a, n, k) << endl;
    }
    return 0;
}
