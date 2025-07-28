/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 1
* Programming Fundamentals Summer 2025
* Date: 13.07.2025
*/

// The library here is concretely set, students are not allowed to include any other libraries.

#include "dragon.h"

// Nhiệm vụ 1
void runSingleTestcase1(const string& inputFile, int expectedResult) {
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
    runSingleTestcase1("testcase/test-41/test001.txt", 1);
    runSingleTestcase1("testcase/test-41/test002.txt", 4);
    runSingleTestcase1("testcase/test-41/test003.txt", 5);
    runSingleTestcase1("testcase/test-41/test004.txt", 9);
    runSingleTestcase1("testcase/test-41/test005.txt", 6);
    runSingleTestcase1("testcase/test-41/test006.txt", 7);
    runSingleTestcase1("testcase/test-41/test007.txt", 8);
    runSingleTestcase1("testcase/test-41/test008.txt", 9);
    runSingleTestcase1("testcase/test-41/test009.txt", 10);
    runSingleTestcase1("testcase/test-41/test010.txt", 101);
    runSingleTestcase1("testcase/test-41/test011.txt", 503);
    runSingleTestcase1("testcase/test-41/test012.txt", 103);
    runSingleTestcase1("testcase/test-41/test013.txt", 904);
    runSingleTestcase1("testcase/test-41/test014.txt", 902);
    runSingleTestcase1("testcase/test-41/test015.txt", 1004);
    runSingleTestcase1("testcase/test-41/test016.txt", 1002);
    runSingleTestcase1("testcase/test-41/test017.txt", 102);
    runSingleTestcase1("testcase/test-41/test018.txt", 1003);
}

// Nhiệm vụ 2
void runSingleTestcase2(const string& inputFile, int T, string expectedResult) {
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

void runTestcase2() {
    runSingleTestcase2("testcase/test-42/test001.txt", 6, "Hookfang");
    runSingleTestcase2("testcase/test-42/test002.txt", 6, "None");
    runSingleTestcase2("testcase/test-42/test003.txt", 6, "HookAfang");
    runSingleTestcase2("testcase/test-42/test004.txt", 6, "Hook#fang");
}

// Nhiệm vụ 3.1
void runSingleTestcase31(const string& inputFile, string warriorName, int warriorSkill) {
    cout << "Running test case: " << inputFile << endl;

    int read = readFile(inputFile, dragons, dragonDamages, N);
    compatibilityCheck(dragons, warriorName, warriorSkill);

    cout << endl << "---------------------------------------" << endl;
}

void runTestcase31() {
    runSingleTestcase31("testcase/test-43/test001.txt", "Hiccup", 9);
    runSingleTestcase31("testcase/test-43/test002.txt", "Snotlout", 6);
    runSingleTestcase31("testcase/test-43/test003.txt", "Fish@legs", 7);
}

// Nhiệm vụ 3.2
void runSingleTestcase32(const string& inputFile, Dragon dragons[], string warrior[][3]) {
    cout << "Running test case: " << inputFile << endl;

    int read = readFile(inputFile, dragons, dragonDamages, N);
    buddyMatching(dragons, warrior);

    cout << endl << "---------------------------------------" << endl;
}

void runTestcase32() {
    const int W1 = 5; // or however many warriors you have
    string warrior1[W1][3];
    warrior1[0][0] = "Hiccup"; warrior1[0][1] = "9"; warrior1[0][2] = "0";
    warrior1[1][0] = "Astrid"; warrior1[1][1] = "8"; warrior1[1][2] = "1";
    warrior1[2][0] = "Snotlout"; warrior1[2][1] = "7"; warrior1[2][2] = "2";
    warrior1[3][0] = "Fishlegs"; warrior1[3][1] = "4"; warrior1[3][2] = "3";
    warrior1[4][0] = "Ruff and Tuff"; warrior1[4][1] = "6"; warrior1[4][2] = "4";
    runSingleTestcase32("testcase/test-44/test001.txt", dragons, warrior1);

    const int W2 = 5; // or however many warriors you have
    string warrior2[W2][3];
    warrior2[0][0] = "Hiccup"; warrior2[0][1] = "9"; warrior2[0][2] = "0";
    warrior2[1][0] = "Astrid"; warrior2[1][1] = "8"; warrior2[1][2] = "1";
    warrior2[2][0] = "Snotlout"; warrior2[2][1] = "7"; warrior2[2][2] = "2";
    warrior2[3][0] = "Fishlegs"; warrior2[3][1] = "4"; warrior2[3][2] = "3";
    warrior2[4][0] = "Ruff and Tuff"; warrior2[4][1] = "2"; warrior2[4][2] = "4";
    runSingleTestcase32("testcase/test-44/test002.txt", dragons, warrior2);

    const int W3 = 5; // or however many warriors you have
    string warrior3[W3][3];
    warrior3[0][0] = "Hiccup"; warrior3[0][1] = "2"; warrior3[0][2] = "0";
    warrior3[1][0] = "Astrid"; warrior3[1][1] = "2"; warrior3[1][2] = "1";
    warrior3[2][0] = "Snotlout"; warrior3[2][1] = "2"; warrior3[2][2] = "2";
    warrior3[3][0] = "Fishlegs"; warrior3[3][1] = "2"; warrior3[3][2] = "3";
    warrior3[4][0] = "Ruff and Tuff"; warrior3[4][1] = "2"; warrior3[4][2] = "4";
    runSingleTestcase32("testcase/test-44/test003.txt", dragons, warrior3);

    const int W4 = 5; // or however many warriors you have
    string warrior4[W4][3];
    warrior4[0][0] = "Hiccup"; warrior4[0][1] = "2"; warrior4[0][2] = "0";
    warrior4[1][0] = "Astrid"; warrior4[1][1] = "7"; warrior4[1][2] = "1";
    warrior4[2][0] = "Snotlout"; warrior4[2][1] = "9"; warrior4[2][2] = "2";
    warrior4[3][0] = "Fishlegs"; warrior4[3][1] = "8"; warrior4[3][2] = "3";
    warrior4[4][0] = "Ruff and Tuff"; warrior4[4][1] = "4"; warrior4[4][2] = "4";
    runSingleTestcase32("testcase/test-44/test004.txt", dragons, warrior4);
}

// Nhiệm vụ 4
void runSingleTestcase4(const string& inputFile, Dragon dragons[], string warrior[][3], int map[10][10]) {
    cout << "Running test case: " << inputFile << endl;

    int read = readFile(inputFile, dragons, dragonDamages, N);
    computeChallengeTime(warrior, map);

    cout << endl << "---------------------------------------" << endl;
}

void runTestcase4() {
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
    runSingleTestcase4("testcase/test-45/test001.txt", dragons, warrior, map);
}

// Nhiệm vụ 5.1
void runSingleTestcase51(const string& inputFile, Dragon dragons[], string warrior[][3]) {
    cout << "Running test case: " << inputFile << endl;

    int read = readFile(inputFile, dragons, dragonDamages, N);
    int teamsDamage[N];
    fighterDamage(dragons, warrior, teamsDamage);

    cout << endl << "---------------------------------------" << endl;
}

void runTestcase51() {
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
    runSingleTestcase51("testcase/test-46/test001.txt", dragons, warrior);
}

//Nhiệm vụ 5.2.1
void runSingleTestcase521(const string& inputFile, Dragon dragons[], int map[10][10], int expectX, int expectY) {
    cout << "Running test case: " << inputFile << endl;
    int heritageX;
    int heritageY;

    int read = readFile(inputFile, dragons, dragonDamages, N);
    findHeritageLocation(map, heritageX, heritageY);

    cout << "X: " << heritageX << " Y: " << heritageY << endl;
    if(heritageX == expectX && heritageY == expectY) {
        cout << "✅ Passed";
    } else {
        cout << " ❌ Failed (Expected: " << "X: " << expectX <<" Y: " << expectY << ")";
    }

    cout << endl << "---------------------------------------" << endl;
}

void runTestcase521() {
    int map1[10][10] = {
        {3,  8,  4,  6,  7,  1,  2,  5,  9, 10},
        {6,  7,  5,  3,  4,  2,  9,  8,  1, 11},
        {9,  6,  3,  5,  2, 10, 7,  4,  8, 12},
        {8,  5,  6,  7,  3, 11, 10, 9, 2, 13},
        {7,  4,  9,  8,  1, 12, 11, 10, 3, 14},
        {51, 52,  53,  54,  50, 55, 56, 57, 58, 59},
        {11, 2,  1, 10, 6, 14, 13, 12, 5, 16},
        {12, 1, 10, 11, 7, 15, 14, 13, 6, 17},
        {13, 0, 11, 12, 8, 16, 15, 14, 7, 18},
        {14, 9, 12, 13, 9, 17, 16, 15, 8, 19}
    };
    runSingleTestcase521("testcase/test-47/test001.txt", dragons, map1, 5, 4);

    int map2[10][10] = {
        {13,  18,  14,  16,  15,  14,  13,  12, 11, 10},
        {6,  7,  5,  3,  4,  2,  9,  8,  1, 1},
        {9,  6,  3,  5,  2, 10, 7,  4,  8, 2},
        {8,  5,  6,  7,  3, 11, 10, 9, 2, 3},
        {7,  4,  9,  8,  1, 12, 11, 10, 3, 4},
        {4, 5,  6,  7,  8, 9, 10, 11, 12, 3},
        {11, 2,  1, 10, 6, 14, 13, 12, 5, 6},
        {12, 1, 10, 11, 7, 15, 14, 13, 6, 7},
        {13, 0, 11, 12, 8, 16, 15, 14, 7, 8},
        {14, 9, 12, 13, 9, 17, 16, 15, 8, 9}
    };
    runSingleTestcase521("testcase/test-47/test001.txt", dragons, map2, 0, 9);

    int map3[10][10] = {
        { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 },
        { 15, 25, 35, 45, 55, 65, 75, 85, 95, 105 },
        { 12, 22, 32, 42, 52, 62, 72, 82, 92, 175 },
        { 118, 128, 138, 50, 58, 68, 78, 88, 98, 108 },
        { 14, 24, 34, 44, 54, 64, 74, 84, 94, 104 },
        { 19, 29, 39, 49, 59, 69, 79, 89, 99, 109 },
        { 11, 21, 31, 41, 51, 61, 71, 81, 91, 101 },
        { 16, 26, 36, 46, 56, 66, 76, 186, 96, 106 },
        { 17, 27, 37, 47, 57, 67, 196, 87, 90, 107 },
        { 13, 23, 33, 43, 53, 63, 73, 153, 93, 170 }
    };
    runSingleTestcase521("testcase/test-47/test001.txt", dragons, map3, 3, 3);
}

// Nhiệm vụ 5.2.2
void runSingleTestcase522(const string& inputFile, Dragon dragons[], int map[10][10], int expectX, int expectY) {
    cout << "Running test case: " << inputFile << endl;
    int keyX;
    int keyY;

    int read = readFile(inputFile, dragons, dragonDamages, N);
    findKeyLocation(map, keyX, keyY);

    cout << "X: " << keyX << " Y: " << keyY << endl;
    if(keyX == expectX && keyY == expectY) {
        cout << "✅ Passed";
    } else {
        cout << " ❌ Failed (Expected: " << "X: " << expectX <<" Y: " << expectY << ")";
    }

    cout << endl << "---------------------------------------" << endl;
}

void runTestcase522() {
    int map1[10][10] = {
        {3,  8,  4,  6,  7,  1,  2,  5,  9, 10},
        {6,  7,  5,  3,  4,  2,  9,  8,  1, 11},
        {9,  6,  3,  5,  2, 10, 7,  4,  8, 12},
        {8,  5,  6,  7,  3, 11, 10, 9, 2, 13},
        {7,  4,  9,  8,  1, 12, 11, 10, 3, 14},
        {51, 52,  53,  54,  50, 55, 56, 57, 58, 59},
        {11, 2,  1, 10, 6, 14, 13, 12, 5, 16},
        {12, 1, 10, 11, 7, 15, 14, 13, 6, 17},
        {13, 0, 11, 12, 8, 16, 15, 14, 7, 18},
        {14, 9, 12, 13, 9, 17, 16, 15, 8, 19}
    };
    runSingleTestcase522("testcase/test-48/test001.txt", dragons, map1, 6, 6);

    int map2[10][10] = {
        {13, 18,  14, 16, 15, 14, 13, 12, 11, 10},
        {6,  7,  5,  3,  4,  2,  9,  8,  1, 1},
        {9,  6,  3,  5,  2, 10, 7,  4,  8, 2},
        {8,  5,  6,  7,  3, 11, 10, 9, 2, 3},
        {7,  4,  9,  8,  1, 12, 11, 10, 3, 4},
        {4, 5,  6,  7,  8, 9, 10, 11, 12, 3},
        {11, 2,  1, 10, 6, 14, 13, 12, 5, 6},
        {12, 1, 10, 11, 7, 50, 50, 50, 6, 7},
        {13, 0, 11, 12, 8, 50, 15, 50, 7, 8},
        {14, 9, 12, 13, 9, 50, 50, 50, 8, 9}
    };
    runSingleTestcase522("testcase/test-48/test001.txt", dragons, map2, 8, 6);

    int map3[10][10] = {
        { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 },
        { 15, 25, 35, 45, 55, 65, 75, 85, 95, 105 },
        { 12, 22, 32, 42, 52, 62, 72, 82, 92, 175 },
        { 118, 128, 138, 50, 58, 68, 78, 88, 98, 108 },
        { 14, 24, 34, 44, 54, 64, 74, 84, 94, 104 },
        { 19, 29, 39, 49, 59, 69, 79, 89, 99, 109 },
        { 11, 21, 31, 41, 51, 61, 71, 81, 91, 101 },
        { 16, 26, 36, 46, 56, 66, 76, 186, 96, 106 },
        { 17, 27, 37, 47, 57, 67, 196, 87, 90, 107 },
        { 13, 23, 33, 43, 53, 63, 73, 153, 93, 170 }
    };
    runSingleTestcase522("testcase/test-48/test001.txt", dragons, map3, 8, 8);
}

// Nhiệm vụ 5.2.3
void runSingleTestcase523(const string& inputFile, int map[10][10], int warriorDamage, int HP) {
    cout << "Running test case: " << inputFile << endl;
    totalTime(map, warriorDamage, HP);

    cout << endl << "---------------------------------------" << endl;
}

void runTestcase523() {
    int map[10][10] = {
        { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 },
        { 15, 25, 35, 45, 55, 65, 75, 85, 95, 105 },
        { 12, 22, 32, 42, 52, 62, 72, 82, 92, 175 },
        { 118, 128, 138, 50, 58, 68, 78, 88, 98, 108 },
        { 14, 24, 34, 44, 54, 64, 74, 84, 94, 104 },
        { 19, 29, 39, 49, 59, 69, 79, 89, 99, 109 },
        { 11, 21, 31, 41, 51, 61, 71, 81, 91, 101 },
        { 16, 26, 36, 46, 56, 66, 76, 186, 96, 106 },
        { 17, 27, 37, 47, 57, 67, 196, 87, 90, 107 },
        { 13, 23, 33, 43, 53, 63, 73, 153, 93, 170 }
    };
    runSingleTestcase523("testcase/test-49/test001.txt", map, 150, 20);
}

// void runSpecificTestcase(int index, int expectedResult) {
//     string inputFile = "testcase/test0" + to_string(index) + ".txt";
//     runSingleTestcase(inputFile, expectedResult);
// }

int main() {
    // nhiệm vụ 1
    // runTestcase1();

    // nhiệm vụ 2
    // runTestcase2();

    // Nhiệm vụ 3.1
    // runTestcase31();

    // Nhiệm vụ 3.2
    // runTestcase32();

    // Nhiệm vụ 4
    // runTestcase4();

    // Nhiệm vụ 5.1
    // runTestcase51();

    // Nhiệm vụ 5.2.1
    // runTestcase521();

    // Nhiệm vụ 5.2.2
    // runTestcase522();

    // Nhiệm vụ 5.2.3
    runTestcase523();

    // runSpecificTestcase(1, 1);

    return 0;
}
