#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to calculate the sum of powers of prime factors for a number
    int PF(int n){
        int sumOfPower = 0;

        // Check for divisibility by 2 and count powers of 2
        while (n % 2 == 0) { 
            sumOfPower++;
            n = n / 2;
        } 

        // Check for divisibility by odd primes and count their powers
        for (int i = 3; i <= sqrt(n); i = i + 2) { 
            while (n % i == 0) { 
                sumOfPower++;
                n = n / i;
            } 
        } 

        // If there's a prime factor > sqrt(n), count its power
        if (n > 2) 
            sumOfPower++;
        
        return sumOfPower;
    }
    
    // Function to compute the sum of powers of prime factors for numbers in the range [a, b]
	int sumOfPowers(int a, int b){
	    int ans = 0;

        // Iterate through the range [a, b]
	    for(int i = a; i <= b; i++){
	        ans += PF(i); // Add the sum of powers for each number in the range
	    }
	    return ans; // Return the total sum of powers for the range [a, b]
	}
};

int main(){
    int tc;
    cin >> tc; // Input for the number of test cases
    
    while(tc--){
        int a, b;
        cin >>  a >> b; // Input for the range [a, b]

        Solution obj; // Create an object of class Solution
        int ans = obj.sumOfPowers(a, b); // Calculate the sum of powers of prime factors
        cout << ans << "\n"; // Print the result for each test case
    }
    return 0;
}
