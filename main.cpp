/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 1
* Programming Fundamentals Summer 2025
* Date: 13.07.2025
*/

// The library here is concretely set, students are not allowed to include any other libraries.

#include "dragon.h"

#include <iostream>
#include <sstream>
#include <functional>
#include <string>

using namespace std;

void runTestcase(const string& testName, const function<void()>& testFunction, const string& expectedOutput) {
    // Redirect cout to a stringstream
    stringstream buffer;
    streambuf* oldCout = cout.rdbuf(buffer.rdbuf());

    // Run the provided test logic
    testFunction();

    // Restore cout
    cout.rdbuf(oldCout);

    string actualOutput = buffer.str();

    if (actualOutput == expectedOutput) {
        cout << "[PASS] " << testName << endl;
    } else {
        cout << "[FAIL] " << testName << endl;
        cout << "Expected:\n------------------\n" << expectedOutput;
        cout << "\nActual:\n------------------\n" << actualOutput;
    }
}

void testMission1() {
    cout << "Mission 1: " << endl;
    runTestcase(
        "Testcase 1",
        []() {
            cout << readFile("testcases/mission1/tnc_tc_01_input.txt", dragons, dragonDamages, N) << endl;
        },
        "1\n"
    );

    runTestcase(
        "Testcase 2",
        []() {
            cout << readFile("testcases/mission1/tnc_tc_02_input.txt", dragons, dragonDamages, N) << endl;
        },
        "4\n"
    );
    
    runTestcase(
        "Testcase 3",
        []() {
            cout << readFile("testcases/mission1/tnc_tc_03_input.txt", dragons, dragonDamages, N) << endl;
        },
        "5\n"
    );
    
    runTestcase(
        "Testcase 4",
        []() {
            cout << readFile("testcases/mission1/tnc_tc_04_input.txt", dragons, dragonDamages, N) << endl;
        },
        "9\n"
    );

    runTestcase(
        "Testcase 5",
        []() {
            cout << readFile("testcases/mission1/tnc_tc_05_input.txt", dragons, dragonDamages, N) << endl;
        },
        "101\n"
    );

    runTestcase(
        "Testcase 6",
        []() {
            cout << readFile("testcases/mission1/tnc_tc_06_input.txt", dragons, dragonDamages, N) << endl;
        },
        "503\n"
    );

    runTestcase(
        "Testcase 7",
        []() {
            cout << readFile("testcases/mission1/tnc_tc_07_input.txt", dragons, dragonDamages, N) << endl;
        },
        "904\n"
    );

    runTestcase(
        "Testcase 8",
        []() {
            cout << readFile("testcases/mission1/tnc_tc_08_input.txt", dragons, dragonDamages, N) << endl;
        },
        "1003\n"
    );

    cout << "----------" << endl;
}

void testMission2() {
    cout << "Mission 2: " << endl;

    runTestcase(
        "Testcase 1",
        []() {
            cout << readFile("testcases/mission2/tnc_tc_01_input.txt", dragons, dragonDamages, N) << endl;
            cout << findKthStrongestDragon(dragons, dragonDamages, N, 6) << endl;
        },
        "1\n"
        "Hookfang\n"
    );

    runTestcase(
        "Testcase 2",
        []() {
            cout << readFile("testcases/mission2/tnc_tc_02_input.txt", dragons, dragonDamages, N) << endl;
            cout << findKthStrongestDragon(dragons, dragonDamages, N, 6) << endl;
        },
        "1\n"
        "None\n"
    );

    cout << "----------" << endl;
}

void testMission3() {
    cout << "Mission 3: " << endl;

    runTestcase(
        "Testcase 1",
        []() {
            cout << readFile("testcases/mission3/tnc_tc_01_input.txt", dragons, dragonDamages, N) << endl;
            compatibilityCheck(dragons, "Hiccup", 6);
        },
        "1\n"
        "Warrior      Dragon        Compatibility    Review\n"
        "Hiccup       Toothless     3.50             Not Compatible\n"
        "Hiccup       Stormfly      4.00             Not Compatible\n"
        "Hiccup       Hookfang      4.50             Compatible\n"
        "Hiccup       Meatlug       4.50             Compatible\n"
        "Hiccup       Barf and Belch5.00             Compatible\n"
    );

    runTestcase(
        "Testcase 2",
        []() {
            cout << readFile("testcases/mission3/tnc_tc_02_input.txt", dragons, dragonDamages, N) << endl;
            compatibilityCheck(dragons, "Astrid", 2);
        },
        "1\n"
        "Warrior      Dragon        Compatibility    Review\n"
        "Astrid       Toothless     4.50             Compatible\n"
        "Astrid       Stormfly      5.00             Compatible\n"
        "Astrid       Hookfang      4.00             Not Compatible\n"
    );

    // runTestcase(
    //     "Testcase 13",
    //     []() {
    //         cout << readFile("testcases/tnc_tc_11_input.txt", dragons, dragonDamages, N) << endl;
    //         string warriors_13[5][3] = {
    //             {"Hiccup", "8", "0"},
    //             {"Astrid", "7", "1"},
    //             {"Snotlout", "9", "2"},
    //             {"Fishlegs", "6", "3"},
    //             {"Ruff&Tuff", "7", "4"},
    //         };
    //         buddyMatching(dragons, warriors_13);
    //     },
    //     "1\n"
    //     "Warrior      Dragon        Compatibility    Review\n"
    //     "Hiccup       Stormfly      5.00             Compatible\n"
    //     "Astrid       Hookfang      5.00             Compatible\n"
    //     "Snotlout     Toothless     5.00             Compatible\n"
    //     "Fishlegs     Barf and Belch5.00             Compatible\n"
    //     "Ruff&Tuff    Meatlug       5.00             Compatible\n"
    // );

    // runTestcase(
    //     "Testcase 14",
    //     []() {
    //         cout << readFile("testcases/tnc_tc_12_input.txt", dragons, dragonDamages, N) << endl;
    //         string warriors_14[3][3] = {
    //             {"Valka", "10", "0"},
    //             {"Eret", "6", "1"},
    //             {"Gobber", "4", "2"},
    //         };
    //         buddyMatching(dragons, warriors_14);
    //     },
    //     "1\n"
    //     "Warrior      Dragon        Compatibility    Review\n"
    //     "Valka        Hookfang      2.00             Not Compatible\n"
    //     "Eret         Toothless     3.50             Not Compatible\n"
    //     "Gobber       Stormfly      4.00             Not Compatible\n"
    // );

    cout << "----------" << endl;
}

void testMission4() {
    cout << "Mission 4: " << endl;

    runTestcase(
        "Testcase 1",
        []() {
            readFile("testcases/mission4/tnc_tc_01_input.txt", dragons, dragonDamages, N);
            string fighters_1[5][3] = {
                {"Hiccup", "8", "0"},
                {"Astrid", "7", "1"},
                {"Snotlout", "9", "2"},
                {"Fishlegs", "6", "3"},
                {"Ruff&Tuff", "7", "4"},
            };

            int map_1[10][10] = {
                {11, 20, 30, 40, 50, 60, 70, 80, 90, 100},
                {15, 25, 35, 45, 55, 65, 75, 85, 1, 105},
                {12, 22, 32, 42, 52, 62, 72, 82, 10, 175},
                {118, 128, 138, 50, 58, 68, 78, 88, 98, 108},
                {14, 24, 34, 44, 54, 64, 74, 84, 94, 104},
                {19, 29, 39, 49, 59, 33, 79, 89, 99, 109},
                {11, 21, 14, 41, 51, 61, 71, 81, 91, 101},
                {16, 26, 36, 46, 56, 66, 76, 186, 96, 106},
                {17, 27, 37, 47, 57, 67, 196, 87, 90, 107},
                {13, 23, 33, 43, 53, 63, 73, 153, 93, 22}};

            computeChallengeTime(fighters_1, map_1);
        },
        "Warrior        Total time (secs)\n"
        "Hiccup         500\n"
        "Snotlout       500\n"
        "Fishlegs       500\n"
        "Ruff&Tuff      500\n"
    );

    runTestcase(
        "Testcase 2",
        []() {
            readFile("testcases/mission4/tnc_tc_02_input.txt", dragons, dragonDamages, N);
            string fighters_2[5][3] = {
                {"Valka", "8", "1"},
                {"Eret", "5", "2"},
                {"Stoick", "10", "3"},
                {"Grimmel", "7", "0"},
                {"Spitelout", "6", "4"},
            };

            int map_2[10][10] = {
                {5, 10, 15, 20, 25, 30, 35, 40, 45, 50},
                {2, 12, 22, 32, 42, 52, 62, 72, 82, 92},
                {3, 13, 23, 33, 43, 53, 63, 73, 83, 93},
                {4, 14, 24, 34, 44, 54, 64, 74, 84, 94},
                {6, 16, 26, 36, 46, 56, 66, 76, 86, 96},
                {7, 17, 27, 37, 47, 57, 67, 77, 87, 97},
                {8, 18, 28, 38, 48, 58, 68, 78, 88, 98},
                {9, 19, 29, 39, 49, 59, 69, 79, 89, 99},
                {1, 11, 21, 31, 41, 51, 61, 71, 81, 91},
                {0, 100, 200, 300, 400, 500, 600, 700, 800, 900}};

            computeChallengeTime(fighters_2, map_2);
        },
        "Warrior        Total time (secs)\n"
        "Eret           515\n"
        "Stoick         530\n"
        "Spitelout      535\n"
        "Grimmel        540\n"
    );

    cout << "----------" << endl;
}

void testMission51() {
    cout << "Mission 5-1: " << endl;

    runTestcase(
        "Testcase 2",
        []() {
            readFile("testcases/mission51/tnc_tc_02_input.txt", dragons, dragonDamages, N);
            string fighters_2[5][3] = {
                {"Valka", "8", "1"},
                {"Eret", "5", "2"},
                {"Stoick", "10", "3"},
                {"Grimmel", "7", "0"},
                {"Spitelout", "6", "4"},
            };

          int teamDamage_2[5];
            fighterDamage(dragons, fighters_2, teamDamage_2);

        },
        "1\n"
        "Valka-Toothless: damage = 140\n"
        "Eret-Stormfly: damage = 185\n"
        "Stoick-Meatlug: damage = 190\n"
        "Grimmel-BarfBelch: damage = 215\n"
        "Spitelout-Hookfang: damage = 230\n"
    );


    cout << "----------" << endl;
}

void testMission52() {
    cout << "Mission 5-2: " << endl;

    runTestcase(
        "Testcase 1",
        []() {
            int map_1[10][10] = {
                {10, 20, 30, 40, 50, 60, 70, 80, 90, 100},
                {15, 25, 35, 45, 55, 65, 75, 85, 95, 105},
                {12, 22, 32, 42, 52, 62, 72, 82, 92, 175},
                {118, 128, 138, 50, 58, 68, 78, 88, 98, 108},
                {14, 24, 34, 44, 54, 64, 74, 84, 94, 104},
                {19, 29, 39, 49, 59, 69, 79, 89, 99, 109},
                {11, 21, 31, 41, 51, 61, 71, 81, 91, 101},
                {16, 26, 36, 46, 56, 66, 76, 186, 96, 106},
                {17, 27, 37, 47, 57, 67, 196, 87, 90, 107},
                {11, 23, 33, 43, 53, 63, 73, 153, 93, 170}};

            int playerDamage_1 = 150;
            totalTime(map_1, playerDamage_1, 20);
        },
        "Total time: 627 (sec)\n"
        "Remaining HP: 15\n"
        "Path: (0,0) (0,1) (0,2) (0,3) (0,4) (0,5) (0,6) (0,7) (0,8) (0,9) (1,9) (1,8) (1,7) (1,6) (1,5) (1,4) (1,3) (1,2) (1,1) (1,0) (2,0) (2,1) (2,2) (2,3) (2,4) (2,5) (2,6) (2,7) (2,8) (2,9) (1,9) (1,8) (1,7) (1,6) (1,5) (1,4) (1,3) (1,2) (1,1) (1,0) (2,0) (2,1) (2,2) (2,3) (2,4) (2,5) (2,6) (2,7) (2,8) (2,9) (3,9) (3,8) (3,7) (3,6) (3,5) (3,4) (3,3) (3,2) (3,1) (3,0) (4,0) (4,1) (4,2) (4,3) (4,4) (4,5) (4,6) (4,7) (4,8) (4,9) (5,9) (5,8) (5,7) (5,6) (5,5) (5,4) (5,3) (5,2) (5,1) (5,0) (6,0) (6,1) (6,2) (6,3) (6,4) (6,5) (6,6) (6,7) (6,8) (6,9) (7,9) (7,8) (7,7) (7,6) (7,5) (7,4) (7,3) (7,2) (7,1) (7,0) (8,0) (8,1) (8,2) (8,3) (8,4) (8,5) (8,6) (6,8) (6,9) (7,9) (7,8) (7,7) (7,6) (7,5) (7,4) (7,3) (7,2) (7,1) (7,0) (8,0) (8,1) (8,2) (8,3) (8,4) (8,5) (8,6) (8,7) (8,8) (8,7) (8,6) (8,5) (8,4) (8,3) (8,2) (8,1) (8,0) (7,0) (7,1) (7,2) (7,3) (7,4) (7,5) (7,6) (7,7) (7,8) (7,9) (6,9) (6,8) (6,7) (6,6) (6,5) (6,4) (6,3) (6,2) (6,1) (6,0) (5,0) (5,1) (5,2) (5,3) (5,4) (5,5) (5,6) (5,7) (5,8) (5,9) (4,9) (4,8) (4,7) (4,6) (4,5) (4,4) (4,3) (4,2) (4,1) (4,0) (3,0) (3,1) (3,2) (3,3)\n"
    );

    runTestcase(
        "Testcase 2",
        []() {
            int map_2[10][10] = {
                {10, 20, 30, 40, 50, 60, 70, 80, 90, 100},
                {15, 25, 35, 45, 55, 65, 75, 85, 95, 105},
                {12, 22, 32, 55, 52, 62, 72, 82, 92, 175},
                {18, 28, 18, 50, 58, 68, 78, 88, 98, 108},
                {14, 24, 34, 44, 54, 64, 74, 84, 94, 104},
                {19, 29, 39, 49, 59, 69, 79, 89, 99, 109},
                {11, 21, 31, 41, 51, 61, 71, 81, 91, 101},
                {16, 26, 36, 46, 56, 66, 76, 186, 96, 106},
                {17, 27, 37, 47, 57, 67, 196, 87, 90, 107},
                {33, 53, 35, 43, 53, 63, 73, 153, 93, 170}
            };

            int playerDamage_2 = 150;
            totalTime(map_2, playerDamage_2, 20);
        },
        "Total time: 578 (sec)\n"
        "Remaining HP: 13\n"
        "Path: (0,0) (0,1) (0,2) (0,3) (0,4) (0,5) (0,6) (0,7) (0,8) (0,9) (1,9) (1,8) (1,7) (1,6) (1,5) (1,4) (1,3) (1,2) (1,1) (1,0) (2,0) (2,1) (2,2) (2,3) (2,4) (2,5) (2,6) (2,7) (2,8) (2,9) (1,9) (1,8) (1,7) (1,6) (1,5) (1,4) (1,3) (1,2) (1,1) (1,0) (2,0) (2,1) (2,2) (2,3) (2,4) (2,5) (2,6) (2,7) (2,8) (2,9) (3,9) (3,8) (3,7) (3,6) (3,5) (3,4) (3,3) (3,2) (3,1) (3,0) (4,0) (4,1) (4,2) (4,3) (4,4) (4,5) (4,6) (4,7) (4,8) (4,9) (5,9) (5,8) (5,7) (5,6) (5,5) (5,4) (5,3) (5,2) (5,1) (5,0) (6,0) (6,1) (6,2) (6,3) (6,4) (6,5) (6,6) (6,7) (6,8) (6,9) (7,9) (7,8) (7,7) (7,6) (7,5) (7,4) (7,3) (7,2) (7,1) (7,0) (8,0) (8,1) (8,2) (8,3) (8,4) (8,5) (8,6) (6,8) (6,9) (7,9) (7,8) (7,7) (7,6) (7,5) (7,4) (7,3) (7,2) (7,1) (7,0) (8,0) (8,1) (8,2) (8,3) (8,4) (8,5) (8,6) (8,7) (8,8) (8,9) (9,9) (9,8) (9,7) (9,6) (9,5) (9,4) (9,3) (9,2) (9,1) (9,0)\n"
    );

    cout << "----------" << endl;
}

int main() {
    // testMission1();
    // testMission2();
    // testMission3();
    // testMission4();
    testMission51();
    // testMission52();

    return 0;
}

