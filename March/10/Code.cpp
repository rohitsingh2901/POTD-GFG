#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
    string removeDuplicates(string str) {
        unordered_map<char, int> m; // Initialize a map to store character frequencies
        string ans = ""; // Initialize an empty string to store the result

        // Count the frequencies of each character in the input string
        for (int i = 0; i < str.length(); i++) {
            m[str[i]]++; // Increment the frequency count of the character
        }

        // Iterate through the input string in reverse order to remove duplicates
        for (int i = str.length() - 1; i >= 0; i--) {
            // If the frequency of the character is greater than 1, it's a duplicate
            if (m[str[i]] > 1) {
                m[str[i]]--; // Decrement the frequency count
            } else {
                ans += str[i]; // Add the character to the result string
            }
        }

        // Reverse the result string to obtain the correct order of characters
        reverse(ans.begin(), ans.end());

        return ans; // Return the resulting string with duplicates removed
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}