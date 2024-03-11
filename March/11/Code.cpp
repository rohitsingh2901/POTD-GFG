
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int x)
    {
        // Initialize variables to keep track of current positions in matrices and the count of pairs
        int r1 = 0, c1 = 0, r2 = n - 1, c2 = n - 1, ans = 0;

        // Loop until the pointers are within the valid range
        while (r1 < n && r2 >= 0)
        {
            // Calculate the sum of elements at the current positions in both matrices
            int sum = mat1[r1][c1] + mat2[r2][c2];

            // If the sum is equal to the target 'x', increment the count and update pointers
            if (sum == x)
            {
                ans++;
                c2--; // Move left in mat2
                c1++; // Move right in mat1
            }
            // If the sum is less than 'x', move right in mat1
            else if (sum < x)
            {
                c1++;
            }
            // If the sum is greater than 'x', move left in mat2
            else
            {
                c2--;
            }

            // If c1 exceeds the last column index, reset c1 to 0 and move down in mat1
            if (c1 > n - 1)
            {
                c1 = 0;
                r1++;
            }

            // If c2 goes below the first column index, reset c2 to the last column and move up in mat2
            if (c2 < 0)
            {
                c2 = n - 1;
                r2--;
            }
        }

        // Return the count of pairs whose sum equals 'x'
        return ans;
    }
};

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;

        vector<vector<int>> mat1(n, vector<int>(n, -1));
        vector<vector<int>> mat2(n, vector<int>(n, -1));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> mat1[i][j];
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> mat2[i][j];
            }
        }

        Solution ob;

        cout << ob.countPairs(mat1, mat2, n, x) << "\n";
    }

    return 0;
}