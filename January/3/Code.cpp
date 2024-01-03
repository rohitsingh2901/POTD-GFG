#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestSubstring(string S) {
        int z = -1, o = -1, t = -1; // Variables to store the indices of most recent occurrences of '0', '1', and '2'
        int n = S.length(); // Length of the input string
        int ans = INT_MAX; // Variable to store the minimum length of the substring

        // Loop through the string 'S'
        for (int i = 0; i < n; i++) {
            // Update indices based on the current character encountered
            if (S[i] == '0') {
                z = i;
            } else if (S[i] == '1') {
                o = i;
            } else {
                t = i;
            }

            // If all three characters '0', '1', and '2' have been found at least once
            if (z != -1 && o != -1 && t != -1) {
                // Calculate the minimum length of the substring
                ans = min(ans, i + 1 - min(z, min(o, t)));
            }
        }

        // Return the minimum length found; if no valid substring found, return -1
        return ans == INT_MAX ? -1 : ans;
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}