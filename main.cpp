/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 1
* Programming Fundamentals Summer 2025
* Date: 13.07.2025
*/

// The library here is concretely set, students are not allowed to include any other libraries.

#include "dragon.h"


void runSingleTestcase(const string& inputFile, int expectedResult) {
    cout << "Running test case: " << inputFile << endl;

    int result = readFile(inputFile, dragons, dragonDamages, N);
    cout << "Result code: " << result;
    if (result == expectedResult) {
        cout << " ✅ Passed";
    } else {
        cout << " ❌ Failed (Expected: " << expectedResult << ")";
    }

    cout << endl << "---------------------------------------" << endl;
}

void runTestcase1() {
    for (int i = 1; i <= 5; ++i) {
        string inputFile = "testcase/test0" + to_string(i) + ".txt";
        
        int expectedResult;
        switch (i) {
            case 1: expectedResult = 1; break;
            case 2: expectedResult = 3; break;
            case 3: expectedResult = 3; break;
            case 4: expectedResult = 3; break;
            case 5: expectedResult = 4; break;
            default: expectedResult = 1;
        }

        runSingleTestcase(inputFile, expectedResult);
    }
}

void runSpecificTestcase(int index, int expectedResult) {
    string inputFile = "testcase/test0" + to_string(index) + ".txt";
    runSingleTestcase(inputFile, expectedResult);
}

int main() {
    runTestcase1();

    // runSpecificTestcase(1, 1);

    return 0;
}
