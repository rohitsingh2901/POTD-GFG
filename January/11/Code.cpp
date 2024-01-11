
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string S, int k) {
        // Check if all digits need to be removed
        if (k == S.size()) {
            return "0";
        }

        // Initialize an empty string to simulate the result
        string str = "";

        // Iterate through each digit in the input string
        for (int i = 0; i < S.size(); i++) {
            // Remove digits to minimize the number
            while (str.size() > 0 && k > 0 && str.back() > S[i]) {
                str.pop_back();
                k--;
            }

            // Append current digit to the stack
            str += S[i];
        }

        // Remove any remaining digits if needed
        while (k > 0 && str.size() > 0) {
            str.pop_back();
            k--;
        }

        // Remove leading zeros
        int i = 0;
        while (str[i] == '0' && i < str.size()) {
            i++;
        }

        // Handle the case where the result is "0"
        if (i == str.size()) {
            return "0";
        }

        // Return the final result
        return str.substr(i);
    }
};



int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}
