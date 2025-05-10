#include <iostream>
#include <vector>
#include "functions.h"

enum Nucleotides
{
    U,
    A,
    C,
    G
};
using namespace std;
int main() {
    vector<int> sequence = {G, C, A, U, G, C, U, A, G, C, A, U}; // Index 0–5

    cout << fold(sequence) << endl;


    return 0;
}