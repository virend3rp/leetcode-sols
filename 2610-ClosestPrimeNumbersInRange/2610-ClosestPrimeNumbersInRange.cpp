// Last updated: 4/24/2026, 10:05:53 PM
class Solution {
public:
vector<int> closestPrimes(int left, int right) {
    // Step 1: Use Sieve of Eratosthenes to find all primes up to `right`
    vector<bool> isPrime(right + 1, true);
    isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime

    for (int i = 2; i * i <= right; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= right; j += i) {
                isPrime[j] = false;
            }
        }
    }

    // Step 2: Collect primes in the range [left, right]
    vector<int> primes;
    for (int i = left; i <= right; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }

    // Step 3: Find the closest prime pair
    if (primes.size() < 2) {
        return {-1, -1}; // Not enough primes
    }

    int minDiff = INT_MAX;
    vector<int> result = {-1, -1};

    for (size_t i = 1; i < primes.size(); i++) {
        int diff = primes[i] - primes[i - 1];
        if (diff < minDiff) {
            minDiff = diff;
            result = {primes[i - 1], primes[i]};
        }
    }

    return result;
}
    
};