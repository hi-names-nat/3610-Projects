#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "marked.h"
#include <cmath>

using namespace std;

void sieve(markedInt allNums[], int size, int nextIndex);
int main(int argc, char const *argv[])
{
    /**
     * The number given by the user in which its composites and primes will be given.
     **/
    int ceiling;
    string checkForInts;

    if (argc != 2)
    {
        cout << "Please enter an argument of an integer you would like to display the primes and composites for.\n";
        exit(1);
    }
    checkForInts = argv[1];
    for (int i = 0; i < checkForInts.length(); i++) {
        if (!isdigit(checkForInts[i])) {
            cout << "Please enter an argument in the form of a number." << endl;
            exit(1);
        }
    }
    ceiling = stoi(checkForInts);

     markedInt allNums[ceiling - 2];

    
    
    for (int i = 2; i <= ceiling; i++) {
        allNums[i-2].setVal(i);
        cout << "i: " << i << endl;
        
    }

    string composite = "";
    cout << "prime: ";
    for (int i = 0; i <= ceiling - 1; i++) {
        if (allNums[i].getMarked()) {
            composite += allNums[i].getValue() + " ";
        } else
        {
            cout << allNums[i].getValue() << " ";
        }
        
    }
    cout << "\nComposite: " << composite << endl;
    return 0;
}


void sieve(markedInt allNums[], int size, int nextIndex) {
    if (allNums[nextIndex].getValue() > sqrt(allNums[size-1].getValue()))
    {
        return;
    }

    for (int i = nextIndex; i < size; i += nextIndex) {
        if (i != nextIndex) {
            allNums[i].setMarked(true);
        }
    }

    for (int i = 0; i < size; i++) {
        if (allNums[i].getMarked() == false && nextIndex < allNums[i].getValue()) {
            sieve(allNums, size, allNums[i].getValue());
        }
    }
}
