#include <string>
#include <vector>

class Solution {
private:
    void backtrack(int n,string& current, vector<bool>& visited,vector<string>& allPermutations) {
        // Base case: full permutation formed
        if (current.length() == n) {
            allPermutations.push_back(current);
            return;
        }
        // Try every available digit 1 through n in order
        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) {
                visited[i] = true;
                current.push_back('0' + i);
                
                backtrack(n, current, visited, allPermutations);
                
                // Backtrack step
                current.pop_back();
                visited[i] = false;
            }
        }
    }

public:
    string getPermutation(int n, int k) {
        vector<string> allPermutations;
        string current = "";
        vector<bool> visited(n + 1, false);

        // Generate permutations lexicographically
        backtrack(n, current, visited, allPermutations);

        // Return the k-th targeted permutation (1-indexed input -> 0-indexed vector)
        return allPermutations[k - 1];
    }
};