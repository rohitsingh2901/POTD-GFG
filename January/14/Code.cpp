
#include <bits/stdc++.h> 
using namespace std; 


class Solution
{   
    public:
    vector<int> repeatedRows(vector<vector<int>> &matrix, int M, int N) 
    { 
        // Your code here
        vector<int> ans;
        unordered_map<string, int> m;
    
        for (int i = 0; i < M; i++) {
            string v_str;
            for (int j = 0; j < N; j++) {
                v_str += to_string(matrix[i][j]);
            }
    
            m[v_str]++;
            if (m[v_str] > 1)
                ans.push_back(i);
        }
    
        return ans;
      
    } 
};

int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        vector<int> ans = ob.repeatedRows(matrix, row, col);


        for (int i = 0; i < ans.size(); ++i)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}