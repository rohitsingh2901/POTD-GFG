#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int TotalWays(int N) {
        // Initialize two vectors to store counts of possibilities
        vector<long long int> one(N+1); // For buildings placed
        vector<long long int> zero(N+1); // For empty spaces

        const int MOD = 1000000007; // Modulus value

        // Base cases: when only one plot is available
        one[1] = zero[1] = 1;

        // Calculate possibilities for one side of the road
        for(int i = 2; i <= N; i++) {
            // Calculate the count of possibilities for empty spaces
            zero[i] = (zero[i - 1] + one[i - 1]) % MOD;

            // Calculate the count of possibilities for buildings
            one[i] = zero[i - 1];
        }

        // Calculate total ways for both sides and apply modulo
        long long int ans = (zero[N] + one[N]) % MOD; // Total ways for one side
        ans = (ans * ans) % MOD; // Multiply by itself to cover both sides

        return static_cast<int>(ans); // Return the final answer
    }
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}