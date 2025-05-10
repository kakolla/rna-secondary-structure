#include <iostream>
#include <vector>
#include "functions.h"
#include <fstream>
#include <string>
#include <algorithm>

enum Nucleotides
{
    U,
    A,
    C,
    G
};
using namespace std;
int main() {
    vector<int> sequence;
    ifstream file("sequence.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line, ',')) {
            line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());
            if (line == "U") {
            sequence.push_back(Nucleotides::U);
            } else if (line == "A") {
                sequence.push_back(Nucleotides::A);
            } else if (line == "C") {
                sequence.push_back(Nucleotides::C);
            } else if (line == "G") {
                sequence.push_back(Nucleotides::G);
            }
            }
        
    }
    

    cout << fold(sequence) << endl;


    return 0;
}