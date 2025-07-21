#include "dragon.h"

// ***
// If you don't want to lose a LOT of points, please don't add any libraries here. T_T
// ***

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

Dragon dragons[MAX_DRAGONS];
int dragonDamages[5] = {0, 0, 0, 0, 0};
int N = 0;

// Task 1
bool checkValidLetter(char c) {
    return (
        (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == ' ' || 
        c == '@' || c == '!' || c == '#' || c == '$' ||
        c == '%' || c =='^' || c == '&' || c == '*');
}

int readFile(const string filename, Dragon dragons[], int dragonDamages[5], int &N)
{
    // TODO: Implement this function
    ifstream ifs(filename);

    string DragonNameString;
    string DragonTypeString;
    string DragonTemperamentString;
    string DragonAmmountCountString;
    string DragonDamagesString;
    string RiderNameString;
    string numDragon;

    getline(ifs, DragonNameString);
    getline(ifs, DragonTypeString);
    getline(ifs, DragonTemperamentString);
    getline(ifs, DragonAmmountCountString);
    getline(ifs, DragonDamagesString);
    getline(ifs, RiderNameString);
    getline(ifs, numDragon);

    bool insideQuotes = false;
    string name = "";
    int index = 0;

    // Tách các tên rồng
    for (int i = 0; i < DragonNameString.length(); i++) {
        char c = DragonNameString[i];

        if (c == '"') {
            insideQuotes = !insideQuotes;

            if (!insideQuotes) {
                dragons[index].dragonNames = name;
                index += 1;
                name = "";
            }

            continue;
        }
        if (insideQuotes) {
            if(checkValidLetter(c)){
                name += c;
            }
        }
    }

    insideQuotes = false;
    string typeName = "";
    index = 0;

    // Tách các type rồng
    for(int i = 0; i < DragonTypeString.length(); i++) {
        char c = DragonTypeString[i];

        if(c == '"') {
            insideQuotes = !insideQuotes;

            if(!insideQuotes) {
                if(typeName == "Night Furry") dragons[index].dragonTypes = 1;
                else if(typeName == "Deadly Nadder") dragons[index].dragonTypes = 2;
                else if(typeName == "Monstrous Nightmare") dragons[index].dragonTypes = 3;
                else if(typeName == "Gronckle") dragons[index].dragonTypes = 4;
                else if(typeName == "Hideous Zippleback") dragons[index].dragonTypes = 5;
                else dragons[index].dragonTypes = 1;

                index += 1;
                typeName = "";
            }

            continue;
        }

        if(insideQuotes) {
            typeName += c;
        }
    }

    for(int i = 0; i < 5; i++) {
        cout << dragons[i].dragonNames << " " << dragons[i].dragonTypes << endl;
    }

    if (!ifs.is_open())
    {
        return 3; // File not found
    }

    // Dummy return until implemented
    return 1;
}

// Task 2
string findKthStrongestDragon(Dragon dragons[], int dragonDamages[5], int N, int T)
{
    // TODO: Implement this function
    return "None";
}

// Task 3.1
void compatibilityCheck(Dragon dragons[], string warriorName, int warriorSkill)
{
    // TODO: Implement this function
}

void printCompatibilityTable(string fighterName, string dragonName, float compatibility)
{
    cout << "Warrior      Dragon        Compatibility    Review" << endl;

    string result = (compatibility > 4) ? "Compatible" : "Not Compatible";

    cout << left << setw(13) << fighterName
         << setw(14) << dragonName
         << setw(17) << fixed << setprecision(2) << compatibility
         << result << endl;
}

// Task 3.2
void buddyMatching(Dragon dragons[], string warriors[][3])
{
    // TODO: Implement this function
}

// Task 4
void computeChallengeTime(string warriors[][3], string map[10][10])
{
    // TODO: Implement this function
}

// Task 5.1
void fighterDamage(Dragon dragons[], string warriors[][3], int teamsDamage[])
{
    // TODO: Implement this function
}

// Task 5.2
void findHeritageLocation(int  map[10][10], int &heritageX, int &heritageY) {
    // TODO: Implement this function
}
void findKeyLocation(int map[10][10], int &keyX, int &keyY) {
    // TODO: Implement this function
}
void totalTime(int map[10][10], int warriorDamage, int HP) {
    // TODO: Implement this function
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
