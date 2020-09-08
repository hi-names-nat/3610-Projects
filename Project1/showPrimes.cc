/*********************************
 * 
 * Author: Natalie Soltis
 * 
 * Name: showPrimes.cc
 * 
 * Description: sorts composite and prime numbers up to a given integer 
 *  using the Sieve of Erathosthenes.
 * 
 * Date: 9/8/2020
 * 
 *************************************/



#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "marked.h"
#include <cmath>

using namespace std;

/** 
 * 
 * recursive. Does sieve function
 * 
 * @param: the array to modify
 * @param: the size of the array
 * @param: the first index to set (will always be zero at first, but needed for recursion.)
 **/
void sieve(markedInt allNums[], int size, int nextIndex);


int main(int argc, char const *argv[])
{
    /**
     * The number given by the user in which its composites and primes will be given.
     **/
    int ceiling;

    //used to ensure that ints are passed
    string checkForInts;

    //this section does argument checks.
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

    //init array
    markedInt allNums[ceiling - 1];

    
    //array loading for
    for (int i = 2; i <= ceiling; i++) {
        allNums[i-2].setVal(i);
    }

    sieve(allNums, ceiling - 1, 0);

    //output
    cout << "composite: ";
    for (int i = 0; i <= ceiling - 2; i++) {
        if (allNums[i].getMarked())
            cout << allNums[i].getValue() << " ";
    }
    cout << endl;
    cout << "prime: 1 ";
    for (int i = 0; i <= ceiling - 2; i++) {
        if (!allNums[i].getMarked())
            cout << allNums[i].getValue() << " ";
    }
    cout << endl;
    return 0;
}



void sieve(markedInt allNums[], int size, int nextIndex) {
    int newIndex = -1;
    if (allNums[nextIndex].getValue() > abs(sqrt(allNums[size].getValue())))
    {
        //catcher function. If true ends the stack
        return;
    }

    //sets all numbers of p to be marked
    for (int i = nextIndex + allNums[nextIndex].getValue(); i <= size; i += allNums[nextIndex].getValue()) {
        allNums[i].setMarked(true);
    }
    
    //gets the next index to calculate
    for (int i = nextIndex + allNums[nextIndex].getValue(); i <= size; i++) {
        if (i != nextIndex && !allNums[i].getMarked()) {
            newIndex = i;
            break;
        }
    }

    //recursion with next unmarked integer
    sieve(allNums, size, newIndex);

}
