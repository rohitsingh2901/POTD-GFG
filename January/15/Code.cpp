#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int help(int ind, int n, int total, vector<int> &cost, vector<vector<int>> &dp) {
        // Base case: If we have reached the end of courses
        if (ind == n) return 0;
        
        // Memoization: If the result is already calculated, return it
        if (dp[ind][total] != -1) return dp[ind][total];
        
        // If the remaining total is less than the cost of the current course
        if (total < cost[ind]) {
            // Skip buying the current course and move to the next one
            return dp[ind][total] = help(ind + 1, n, total, cost, dp);
        } else {
            // Calculate the remaining total after buying the current course with 10% refund
            int leftAmount = total - cost[ind];
            int refund = cost[ind] * 0.9;
            leftAmount += refund;

            // Calculate the maximum number of courses by either buying or not buying the current course
            int pick = 1 + help(ind + 1, n, leftAmount, cost, dp);  // Buy the current course
            int notPick = help(ind + 1, n, total, cost, dp);        // Skip the current course

            // Choose the maximum of the two options
            return dp[ind][total] = max(pick, notPick);
        }
    }

    int max_courses(int n, int total, vector<int> &cost) {
        // Initialize the memoization table with -1
        vector<vector<int>> dp(n + 1, vector<int>(total + 1, -1));

        // Call the recursive helper function to find the maximum number of courses
        return help(0, n, total, cost, dp);
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int k;
        cin>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        Solution ob;
        cout<<ob.max_courses(n,k,arr)<<endl;
    }
}