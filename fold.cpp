#include <iostream>
#include <vector>
#include "functions.h"

using namespace std;
enum Nucleotides
{
    U,
    A,
    C,
    G
};

// constraints:
// no sharp turns: (b_i, b_j), i < j -4
// no crossing over: (b_i, b_j), (b_k, b_l), i < j < k < l, or k < i < j < l

/*
OPT(i, j) is max # of pairs of b_i, .. b_j
OPT(i, j) = max {
    OPT(i, j-1),
    max_t {1 + OPT(i,t-1) + OPT(t+1, j-1)} , i <= t < j-4 (hairpin structure)
}
*/


// return max number of pairings
int fold(vector<int> sequence)
{
    int n = sequence.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // init OPT[i, j] = 0 if i >= j - 4
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i >= j - 4)
                dp[i][j] = 0;
        }
    }

    int k = 5; // min distance to not cause a sharp turn
    for (k = 5; k < n; ++k)
    {
        for (int i = 0; i < n - k; ++i)
        {
            int j = i + k;
            int pairs = dp[i][j - 1]; // # of pairs if (i,j) isn't a pair
            for (int t = i; t < j; ++t)
            {
                // consider possible candidates for the hairpin position
                // valid - (bj, bt) must be either {Adenine, uracil} or {cytosine, guanine}
                if (valid(sequence, t, j))
                {
                    int left_pairs = (t - 1 >= i) ? dp[i][t - 1] : 0; // check for bounds
                    int right_pairs = (t + 1 <= j - 1) ? dp[t + 1][j - 1] : 0;
                    cout << i << "," << j << " left: " << left_pairs << " right: " << right_pairs << endl; 
                    pairs = max(pairs,
                                1 + left_pairs + right_pairs);
                }
            }
            dp[i][j] = pairs;
        }
    }
    for (auto row : dp) {
        for (int e : row) {
            cout << e << " ";
        }
        cout << endl;
    }

    return dp[0][n - 1];
}

// return if valid base pair
bool valid(vector<int> sequence, int t, int j)
{
    if ((sequence[j] == A && sequence[t] == U) ||
        (sequence[t] == A && sequence[j] == U) ||
        (sequence[j] == C && sequence[t] == G) ||
        (sequence[t] == C && sequence[j] == G))
    {
        return true;
    }
    return false;
}