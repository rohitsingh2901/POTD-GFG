#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPair(vector<int> nums, int k) {
        if(nums.size() % 2 == 1)
            return false; // If the array length is odd, it's impossible to form pairs
        
        vector<int> arr(k); // Create a vector of size k to store remainder counts
        
        // Loop through the nums array to count remainders when divided by k
        for(int i = 0; i < nums.size(); i++){
            arr[nums[i] % k]++; // Increment count for the remainder when nums[i] is divided by k
        }
        
        int i = 1, j = k - 1;
        if(arr[0] % 2)
            return false; // If remainder 0's count is odd, it's impossible to form pairs
        
        // Check counts of remainders and their complements
        while(i <= j){
            if(arr[i] != arr[j])
                return false; // If counts of different remainders are unequal, return false
            i++;
            j--;
        }
        
        return true; // All counts are equal, indicating that pairs can be formed
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}