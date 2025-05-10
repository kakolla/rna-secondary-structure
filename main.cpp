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
    vector<int> sequence = {A, C, G, U, A, U, C, G, G, C, A, U};

    cout << fold(sequence) << endl;


    return 0;
}