#include<bits/stdc++.h>
using namespace std;


class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
         //Your code here
int n = mat.size(), row = 0, col = 0; // Get the size of the matrix
vector<int> ans; // Initialize an empty vector to store the elements in diagonal pattern
bool isReverse = false; // Initialize a boolean flag to control whether elements should be reversed

    while (col < n) { // Loop until col is less than n
        int i = row, j = col; // Initialize variables for diagonal traversal
        vector<int> temp; // Initialize temporary vector to store elements of current diagonal

        // Traverse the diagonal
        while (i < n && j < n && i >= 0 && j >= 0) {
            temp.push_back(mat[i][j]); // Store current element in temp
            i--; // Move diagonally
            j++;
        }

        if (isReverse) // If flag is set to reverse
            reverse(temp.begin(), temp.end()); // Reverse temp vector

        ans.insert(ans.end(), temp.begin(), temp.end()); // Append temp vector to ans

        if (row != n - 1) { // If not at last row
            row++; // Move to next row
            col = 0; // Reset col to start from beginning
        } else { // If at last row
            col++; // Move to next column
        }

        isReverse = !isReverse; // Toggle flag for next diagonal
        }

        return ans; // Return the result vector containing elements in diagonal pattern

    }
};



int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n;
        int k=0;
        //cin>>k;
        cin>>n;
        vector<vector<int>>mat(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<int>ans = obj.matrixDiagonally(mat);
        for(auto i: ans)cout << i << " ";
        cout << "\n";
        
       
    }
}
