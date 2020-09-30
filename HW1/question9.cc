#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

float getAverage(vector<int> calcVector);

void getStDev(vector<int> calcVector, float avg);

int main(int argc, char const *argv[])
{
    vector<int> XVector;

    cout << "start loading X\n";
    int input = 0;
    cin >> input;
    bool cont = true;
    while (input != -1)
    {
        XVector.push_back(input);
        cout << "continue? y or n\n";

        char yOrN;
        cin >> yOrN;
        if (yOrN == 'n')
        {
            break;
        }

        cout << "input\n";
        cin >> input;
    }
    cout << "average\n";
    cout << getAverage(XVector);

    cout << "standard deviation: ";
    getStDev(XVector, getAverage(XVector));
    

    return (0);
}

float getAverage(vector<int> calcVector)
{
    float newF = 0;
    for (int i = 0; i < calcVector.size(); i++)
    {
        newF += calcVector.at(i);
    }
    return (newF / calcVector.size());
}

void getStDev(vector<int> calcVector, float avg)
{
    float numerator = 0;
    for (int i = 0; i < calcVector.size(); i++)
    {
        numerator += pow((calcVector.at(i) - avg), 2);
    }
    numerator = sqrt(numerator / (calcVector.size() - 1));
    cout <<  numerator;
    return;
}