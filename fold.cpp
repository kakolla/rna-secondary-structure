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

    return 0;
}

// return if valid base pair
bool valid(vector<int> sequence, int t, int j)
{
    if ((sequence[j] == A && sequence[t] == U) ||
        (sequence[t] == A && sequence[j] == U) ||
        (sequence[j] == C && sequence[t] == G) ||
        (sequence[t] == C && sequence[j] == G)) {
        return true;
    }
    return false;
}