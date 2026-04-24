// Last updated: 4/24/2026, 10:05:55 PM
class Solution {
public:
    int mod = 1e9 + 7;

    // Function to calculate power (a^b % mod)
    long long power(long long a, long long b, long long mod) {
        long long result = 1;
        while (b > 0) {
            if (b % 2 == 1) {
                result = (result * a) % mod;
            }
            a = (a * a) % mod;
            b /= 2;
        }
        return result;
    }

    // Function to calculate factorial modulo MOD
    long long factorial(int n) {
        long long fact = 1;
        for (int i = 1; i <= n; i++) {
            fact = (fact * i) % mod;
        }
        return fact;
    }

    // Function to calculate the modular inverse of a number
    long long modInverse(long long a, long long mod) {
        return power(a, mod - 2, mod);  // Fermat's Little Theorem
    }

    // Function to calculate the number of distinct permutations of a single word
    long long distinctPermutations(const string& word) {
        // Count the frequency of each character in the word
        map<char, int> charCount;
        for (const char& c : word) {
            charCount[c]++;
        }

        // Calculate the denominator by multiplying the factorial of the frequencies
        long long denominator = 1;
        for (const auto& entry : charCount) {
            denominator = (denominator * factorial(entry.second)) % mod;
        }

        // Total number of permutations = n! / (k1! * k2! * ... * km!)
        // Using modular inverse to handle division in modulo space
        long long numerator = factorial(word.size());
        long long invDenominator = modInverse(denominator, mod);

        return (numerator * invDenominator) % mod;
    }

    // Function to calculate the total number of distinct anagrams of a sentence
    int countAnagrams(string s) {
        stringstream ss(s);
        string word;
        vector<string> words;

        // Split the sentence into words
        while (ss >> word) {
            words.push_back(word);
        }

        // Calculate the number of distinct anagrams of all the words
        long long final = 1;
        for (const string& word : words) {
            final = (final * distinctPermutations(word)) % mod;
        }

        return final;
    }
};

