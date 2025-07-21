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
    runSingleTestcase("testcase/test01.txt", 1);
    runSingleTestcase("testcase/test02.txt", 4);
    runSingleTestcase("testcase/test03.txt", 5);
    runSingleTestcase("testcase/test04.txt", 9);
    runSingleTestcase("testcase/test05.txt", 6);
    runSingleTestcase("testcase/test06.txt", 7);
    runSingleTestcase("testcase/test07.txt", 8);
    runSingleTestcase("testcase/test08.txt", 9);
    runSingleTestcase("testcase/test09.txt", 10);
    runSingleTestcase("testcase/test010.txt", 101);
    runSingleTestcase("testcase/test011.txt", 503);
    runSingleTestcase("testcase/test012.txt", 103);
    runSingleTestcase("testcase/test013.txt", 904);
    runSingleTestcase("testcase/test014.txt", 902);
    runSingleTestcase("testcase/test015.txt", 1003);
    runSingleTestcase("testcase/test016.txt", 1002);
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
