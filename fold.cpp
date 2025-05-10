#include <iostream>
#include <vector>
#include "functions.h"

using namespace std;
enum Nucleotides {
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
int fold(vector<int> sequence) {
    // int size = sequence.size();
    // vector<vector<int>> dp(size, vector<int>(size, 0));

    // // init OPT[i, j] = 0 if i >= j - 4
    // for (vector<int> row : dp) {
    //     for (int elem : row) {
    //         cout << elem << endl;


    //     }
    // }

    
    return -1;
}