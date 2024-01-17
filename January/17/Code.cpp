#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  
    // Recursive function to generate all unique permutations
    void solve(vector<int> &arr, int index, set<vector<int>>& s) {
        if (index == arr.size()) {
            s.insert(arr);
            return;
        }
        for (int i = index; i < arr.size(); i++) {
            swap(arr[index], arr[i]);
            solve(arr, index + 1, s);
            swap(arr[index], arr[i]);
        }
    }
  
    // Function to find unique permutations using the solve function
    vector<vector<int>> uniquePerms(vector<int> &arr, int n) {
        set<vector<int>> s;
        solve(arr, 0, s);
        vector<vector<int>> ans(s.begin(), s.end());
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr, n);
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < n; j++) {
                cout << res[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
