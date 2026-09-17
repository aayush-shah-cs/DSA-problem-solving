class Solution {
public:
    int countPrimes(int n) {

        if (n <= 2)
            return 0;

        vector<bool> prime(n, true);

        prime[0] = false;
        prime[1] = false;

        // All even numbers greater than 2 are not prime
        for (int i = 4; i < n; i += 2) {
            prime[i] = false;
        }

        // Only check odd numbers
        for (long long i = 3; i * i < n; i += 2) {

            if (prime[i]) {

                // Only mark odd multiples
                for (long long j = i * i; j < n; j += 2 * i) {
                    prime[j] = false;
                }
            }
        }

        int count = 0;

        for (int i = 2; i < n; i++) {
            if (prime[i]) {
                count++;
            }
        }

        return count;
    }
};