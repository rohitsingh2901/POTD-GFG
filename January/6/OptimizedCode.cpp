#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to generate primes using Sieve of Eratosthenes algorithm
    vector<int> sieve(int n) {
        vector<bool> isPrime(n + 1, true);
        vector<int> primes;

        // Mark multiples of each number as non-prime
        for (int p = 2; p * p <= n; ++p) {
            if (isPrime[p]) {
                for (int i = p * p; i <= n; i += p) {
                    isPrime[i] = false;
                }
            }
        }

        // Collect all primes from 2 to n
        for (int p = 2; p <= n; ++p) {
            if (isPrime[p]) {
                primes.push_back(p);
            }
        }

        return primes;
    }

    // Function to calculate the sum of powers of prime factors for a number
    int primeFactorization(int num, const vector<int>& primes) {
        int total = 0;
        for (int prime : primes) {
            // If square of the current prime is greater than num, break the loop
            if (prime * prime > num) break;

            // Check if prime divides num
            if (num % prime == 0) {
                // Count the power of the current prime factor in num
                while (num % prime == 0) {
                    num /= prime;
                    total++;
                }
            }
        }
        
        // If num is greater than 1, it's a prime factor itself
        if (num > 1) total++;

        return total;
    }

    // Function to compute the sum of powers of prime factors for numbers in the range [a, b]
    int sumOfPowers(int a, int b) {
        int totalSum = 0;

        // Generate primes up to b using the sieve function
        vector<int> primes = sieve(b);

        // Iterate through each number from a to b
        for (int i = a; i <= b; ++i) {
            // Calculate the sum of powers of prime factors for each number
            totalSum += primeFactorization(i, primes);
        }

        return totalSum;
    }
};

int main() {
    int tc;
    cin >> tc; // Input for the number of test cases
    while (tc--) {
        int a, b;
        cin >> a >> b; // Input for range [a, b]

        Solution obj; // Create an object of class Solution
        int ans = obj.sumOfPowers(a, b); // Calculate the sum of powers of prime factors
        cout << ans << "\n"; // Print the result for each test case
    }
    return 0;
}
