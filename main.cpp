#include <iostream>
#include <vector>
#include "functions.h"

using namespace std;
int main() {
    vector<int> list(3, 0);
    cout << fold(list) << endl;


    return 0;
}