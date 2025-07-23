/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 1
* Programming Fundamentals Summer 2025
* Date: 13.07.2025
*/

// The library here is concretely set, students are not allowed to include any other libraries.

#include "dragon.h"

void runSingleTestcase41(const string& inputFile, int expectedResult) {
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

void runSingleTestcase42(const string& inputFile, int T, string expectedResult) {
    cout << "Running test case: " << inputFile << endl;

    int read = readFile(inputFile, dragons, dragonDamages, N);
    string result = findKthStrongestDragon(dragons, dragonDamages, N, T); 
    cout << "Result code: " << result;
    if (result == expectedResult) {
        cout << " ✅ Passed";
    } else {
        cout << " ❌ Failed (Expected: " << expectedResult << ")";
    }

    cout << endl << "---------------------------------------" << endl;
}

void runSingleTestcase431(const string& inputFile, string warriorName, int warriorSkill) {
    cout << "Running test case: " << inputFile << endl;

    int read = readFile(inputFile, dragons, dragonDamages, N);
    compatibilityCheck(dragons, warriorName, warriorSkill);

    cout << endl << "---------------------------------------" << endl;
}

void runSingleTestcase432(const string& inputFile, Dragon dragons[], string warrior[][3]) {
    cout << "Running test case: " << inputFile << endl;

    int read = readFile(inputFile, dragons, dragonDamages, N);
    buddyMatching(dragons, warrior);

    cout << endl << "---------------------------------------" << endl;
}

void runSingleTestcase45(const string& inputFile, string warrior[][3], int map[10][10]) {
    cout << "Running test case: " << inputFile << endl;

    int read = readFile(inputFile, dragons, dragonDamages, N);
    computeChallengeTime(warrior, map);

    cout << endl << "---------------------------------------" << endl;
}

// Nhiệm vụ 4.1
void runTestcase1() {
    runSingleTestcase41("testcase/test-41/test001.txt", 1);
    runSingleTestcase41("testcase/test-41/test002.txt", 4);
    runSingleTestcase41("testcase/test-41/test003.txt", 5);
    runSingleTestcase41("testcase/test-41/test004.txt", 9);
    runSingleTestcase41("testcase/test-41/test005.txt", 6);
    runSingleTestcase41("testcase/test-41/test006.txt", 7);
    runSingleTestcase41("testcase/test-41/test007.txt", 8);
    runSingleTestcase41("testcase/test-41/test008.txt", 9);
    runSingleTestcase41("testcase/test-41/test009.txt", 10);
    runSingleTestcase41("testcase/test-41/test010.txt", 101);
    runSingleTestcase41("testcase/test-41/test011.txt", 503);
    runSingleTestcase41("testcase/test-41/test012.txt", 103);
    runSingleTestcase41("testcase/test-41/test013.txt", 904);
    runSingleTestcase41("testcase/test-41/test014.txt", 902);
    runSingleTestcase41("testcase/test-41/test015.txt", 1003);
    runSingleTestcase41("testcase/test-41/test016.txt", 1002);
}

// Nhiệm vụ 4.2
void runTestcase2() {
    runSingleTestcase42("testcase/test-42/test001.txt", 6, "Hookfang");
    runSingleTestcase42("testcase/test-42/test002.txt", 6, "None");
    runSingleTestcase42("testcase/test-42/test003.txt", 6, "HookAfang");
}

// Nhiệm vụ 4.3.1
void runTestcase3() {
    runSingleTestcase431("testcase/test-43/test001.txt", "Hiccup", 9);
    runSingleTestcase431("testcase/test-43/test002.txt", "Snotlout", 6);
}

// Nhiệm vụ 4.3.2
void runTestcase4() {
    const int W = 5; // or however many warriors you have
    string warrior[W][3];
    warrior[0][0] = "Hiccup";
    warrior[0][1] = "9";         
    warrior[0][2] = "0";

    warrior[1][0] = "Astrid";
    warrior[1][1] = "8";
    warrior[1][2] = "1";

    warrior[2][0] = "Snotlout";
    warrior[2][1] = "7";         
    warrior[2][2] = "2";

    warrior[3][0] = "Fishlegs";
    warrior[3][1] = "4";
    warrior[3][2] = "3";

    warrior[4][0] = "Ruff and Tuff";
    warrior[4][1] = "6";         
    warrior[4][2] = "4";
    runSingleTestcase432("testcase/test-44/test001.txt", dragons, warrior);
}

void runTestcase5() {
    int map[10][10] = {
        {0, 1, 2, 3, 4, 5, 0, 1, 2, 3},
        {4, 5, 0, 1, 2, 3, 4, 5, 0, 1},
        {2, 3, 4, 5, 0, 1, 2, 3, 4, 5},
        {0, 1, 2, 3, 4, 5, 0, 1, 2, 3},
        {4, 5, 0, 1, 2, 3, 4, 5, 0, 1},
        {2, 3, 4, 5, 0, 1, 2, 3, 4, 5},
        {0, 1, 2, 3, 4, 5, 0, 1, 2, 3},
        {4, 5, 0, 1, 2, 3, 4, 5, 0, 1},
        {2, 3, 4, 5, 0, 1, 2, 3, 4, 5},
        {0, 1, 2, 3, 4, 5, 0, 1, 2, 3},
    };

    const int W = 5;
    string warrior[W][3];
    warrior[0][0] = "Hiccup";
    warrior[0][1] = "9";         
    warrior[0][2] = "0";

    warrior[1][0] = "Astrid";
    warrior[1][1] = "8";
    warrior[1][2] = "1";

    warrior[2][0] = "Snotlout";
    warrior[2][1] = "7";         
    warrior[2][2] = "2";

    warrior[3][0] = "Fishlegs";
    warrior[3][1] = "4";
    warrior[3][2] = "3";

    warrior[4][0] = "Ruff and Tuff";
    warrior[4][1] = "6";         
    warrior[4][2] = "4";
    runSingleTestcase45("testcase/test-45/test001.txt", warrior, map);
}

// void runSpecificTestcase(int index, int expectedResult) {
//     string inputFile = "testcase/test0" + to_string(index) + ".txt";
//     runSingleTestcase(inputFile, expectedResult);
// }

int main() {
    // runTestcase1();
    // runTestcase2();
    // runTestcase3();
    // runTestcase4();
    runTestcase5();

    // runSpecificTestcase(1, 1);

    return 0;
}
