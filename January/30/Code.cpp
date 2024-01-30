
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[21][21][21]; // Memoization table to store computed results

    // Recursive function to find the length of the longest common subsequence
    int fun(string A, string B, string C, int i, int j, int k)
    {
        // Base case: If any of the indices becomes negative, return 0
        if (i < 0 || j < 0 || k < 0)
            return 0;

        // If the result for the current state is already computed, return it
        if (dp[i][j][k] != -1)
            return dp[i][j][k];

        // If characters at the current indices match, include them and recursively explore
        if (A[i] == B[j] && A[i] == C[k])
        {
            // Include the matched character and recursively find LCS for remaining strings
            return dp[i][j][k] = fun(A, B, C, i - 1, j - 1, k - 1) + 1;
        }
        // If characters don't match, recursively explore all possibilities
        else
        {
            // Exclude one character from each string and find LCS recursively
            return dp[i][j][k] = max(fun(A, B, C, i - 1, j, k),                          // Exclude character from A
                                     max(fun(A, B, C, i, j - 1, k),                      // Exclude character from B
                                         max(fun(A, B, C, i, j, k - 1),                  // Exclude character from C
                                             max(fun(A, B, C, i - 1, j - 1, k),          // Exclude characters from A and B
                                                 max(fun(A, B, C, i - 1, j, k - 1),      // Exclude characters from A and C
                                                     fun(A, B, C, i, j - 1, k - 1)))))); // Exclude characters from B and C
        }
    }

    // Function to find the length of the LCS of three strings
    int LCSof3(string A, string B, string C, int n1, int n2, int n3)
    {
        // Initialize memoization table with -1
        for (int i = 0; i < 21; ++i)
        {
            for (int j = 0; j < 21; ++j)
            {
                for (int k = 0; k < 21; ++k)
                {
                    dp[i][j][k] = -1;
                }
            }
        }

        // Call the recursive function to find LCS and return the result
        return fun(A, B, C, n1 - 1, n2 - 1, n3 - 1);
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        string A, B, C;
        cin >> A >> B >> C;
        Solution obj;
        cout << obj.LCSof3(A, B, C, n1, n2, n3) << endl;
    }
}
