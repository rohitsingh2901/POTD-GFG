
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int longSubarrWthSumDivByK(int arr[], int n, int k) {
            int ans = 0;
            int prefSum = 0;
            unordered_map<int, int> mp; // Hashmap to store remainders and their indices

            for (int i = 0; i < n; i++) {
                prefSum += arr[i];
                int rem = prefSum % k; // Calculate the remainder

                if (rem < 0) rem = k + rem; // Handle negative remainders

                if (rem == 0)
                    ans = max(ans, i + 1); // Update ans if entire subarray till i is divisible by K
                else if (mp.find(rem) != mp.end())
                    ans = max(ans, i - mp[rem]); // Update ans if same remainder encountered again
                else
                    mp[rem] = i; // Store remainder and its index in the hashmap
            }

            return ans; // Return the length of the longest subarray with sum divisible by K
        }
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}