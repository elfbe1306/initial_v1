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
bool checkTxtFile(string s) {
    int length = s.length();
    if(length < 4) return false;
    return s.substr(length - 4) == ".txt";
}

bool checkValidLetter(char c) {
    return (
        (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == ' ' || 
        c == '@' || c == '!' || c == '#' || c == '$' ||
        c == '%' || c =='^' || c == '&' || c == '*');
}

int convertStringToInt(string s) {
    int value = 0;
    for(int i = 0; i < s.length(); i++) {
        value = value * 10 + (s[i] - '0');
    }
    return value;
}

int specialCharCountFun(const string& line) {
    bool insideQuote = false;
    string nameType = "";
    int specialCharCount = 0;

    for(int i = 0; i < line.length(); i++) {
        char c = line[i];

        if(c == '"') {
            insideQuote = !insideQuote;

            if(!insideQuote) {
                nameType = "";
            }
            continue;
        }

        if(insideQuote && checkValidLetter(c)) {
            nameType += c;
            if(c == '@' || c == '!' || c == '#' || c == '$' ||
                c == '%' || c =='^' || c == '&' || c == '*') {
                specialCharCount++;
            }
        }
    }

    return specialCharCount;
}

int spaceCountErrorFun(const string& line) {
    bool insideQuote = false;
    string name = "";

    int spaceErrorCount = 0;

    for(int i = 0; i < line.length(); i++) {
        char c = line[i];

        if(c == '"') {
            insideQuote = !insideQuote;

            if(!insideQuote) {
                for (int j = 1; j < name.length(); j++) {
                    if (name[j] == ' ' && name[j - 1] == ' ') {
                        spaceErrorCount++;
                        break;
                    }
                }
                name = "";
            }
            continue;
        }

        if(insideQuote && checkValidLetter(c)) {
            name += c;
        }
    }
    return spaceErrorCount;
}

int parseDragonNameString(const string& line, Dragon dragons[]) {
    bool insideQuote = false;
    string name = "";
    int index = 0;

    for(int i = 0; i < line.length(); i++) {
        char c = line[i];

        if(c == '"') {
            insideQuote = !insideQuote;

            if(!insideQuote) {
                dragons[index].dragonNames = name;
                index += 1;
                name = "";
            }
            continue;
        }

        if(insideQuote && checkValidLetter(c)) {
            name += c;
        } 
    }
    return index;
}

int parseDragonTypeString(const string& line, Dragon dragons[]) {
    bool insideQuote = false;
    string nameType = "";
    int index = 0;

    for(int i = 0; i < line.length(); i++) {
        char c = line[i];

        if(c == '"') {
            insideQuote = !insideQuote;

            if(!insideQuote) {
                if(nameType == "Night Furry") dragons[index].dragonTypes = 1;
                else if(nameType == "Deadly Nadder") dragons[index].dragonTypes = 2;
                else if(nameType == "Monstrous Nightmare") dragons[index].dragonTypes = 3;
                else if(nameType == "Gronckle") dragons[index].dragonTypes = 4;
                else if(nameType == "Hideous Zippleback") dragons[index].dragonTypes = 5;
                else dragons[index].dragonTypes = 1;
                index += 1;
                nameType = "";
            }
            continue;
        }

        if(insideQuote && checkValidLetter(c)) {
            nameType += c;
        }
    }

    return index;
}

int parseDragonTemperamentString(const string& line, Dragon dragons[]) {
    string temperament = "";
    int index = 0;

    for(int i = 0; i < line.length(); i++) {
        char c = line[i];

        if((c >= '0' && c <= '9') || c == '-') {
            temperament += c;
        }

        if(c == ';' || c == ']') {
            int value = 0;
            if(temperament[0] == '-') {
                dragons[index].dragonTemperament = value;
            } else {
                value = convertStringToInt(temperament);
                if(value > 10) value = 10;
                dragons[index].dragonTemperament = value;
            }
            index += 1;
            temperament = "";
        }
    }
    return index;
}

int parseDragonAmmoCountString(const string& line, Dragon dragons[]) {
    string AmmoCount = "";
    int index = 0;

    for(int i = 0; i < line.length(); i++) {
        char c = line[i];

        if((c >= '0' && c <= '9') || (c == '-')) {
            AmmoCount += c;
        }

        if(c == ';' || c == ']') {
            int value = 0;
            if(AmmoCount[0] == '-') {
                dragons[index].ammoCounts = value;
            } else {
                value = convertStringToInt(AmmoCount);
                if(value > 1000) value = 1000;
                dragons[index].ammoCounts = value;
            }
            index += 1;
            AmmoCount = "";
        }
    }
    return index;
}

int parseDragonDamageString(const string& line, int dragonDamages[]) {
    string damage = "";
    int index = 0;

    for(int i = 0; i < line.length(); i++) {
        char c = line[i];

        if((c >= '0' && c <= '9') || (c == '-')) {
            damage += c;
        }

        if(c == ';' || c == ']') {
            int value = 0;
            if(damage[0] == '-') {
                dragonDamages[index] = value;
            } else {
                value = convertStringToInt(damage);
                dragonDamages[index] = value;
            }
            index += 1;
            damage = "";
        }
    }
    return index;
}

int parseRiderNameString(const string& line, Dragon dragons[]) {
    bool insideQuote = false;
    string riderName = "";
    int index = 0;

    for(int i = 0; i < line.length(); i++) {
        char c = line[i];

        if(c == '"') {
            insideQuote = !insideQuote;

            if(!insideQuote) {
                dragons[index].riderNames = riderName;
                index += 1;
                riderName = "";
            }
            continue;
        }

        if(insideQuote && checkValidLetter(c)) {
            riderName += c;
        }
    }
    return index;
}

int readFile(const string filename, Dragon dragons[], int dragonDamages[5], int &N) {
    // TODO: Implement this function
    // Trả về nếu không phải file .txt
    if(!checkTxtFile(filename)) return 2;

    ifstream ifs(filename);

    //Trả về nếu mở không được
    if (!ifs.is_open()) {
        return 3;
    }

    string DragonNameString, DragonTypeString, DragonTemperamentString, DragonAmmoCountString;
    string DragonDamagesString, RiderNameString, numDragon;

    // Trả về nếu không đủ 7 dòng dữ liệu
    if(!getline(ifs, DragonNameString) || !getline(ifs, DragonTypeString) ||
        !getline(ifs, DragonTemperamentString) || !getline(ifs, DragonAmmoCountString) ||
        !getline(ifs, DragonDamagesString) || !getline(ifs, RiderNameString) ||
        !getline(ifs, numDragon)) return 4;

    // Tổng số rồng
    N = convertStringToInt(numDragon);
    
    // Tách các tên rồng
    int parseNameCount = parseDragonNameString(DragonNameString, dragons);
    if(parseNameCount != N) return 5;

    // Tách các type rồng
    int parseTypeCount = parseDragonTypeString(DragonTypeString, dragons);
    if(parseTypeCount != N) return 6;

    // Tách tính khí của các con rồng
    int parseTemperamentCount = parseDragonTemperamentString(DragonTemperamentString, dragons);
    if(parseTemperamentCount != N) return 7;

    // Tách đạn của các con rồng
    int parseAmmoCount = parseDragonAmmoCountString(DragonAmmoCountString, dragons);
    if(parseAmmoCount != N) return 8;

    // Tách sát thương của các loại rồng
    int parseDamageCount = parseDragonDamageString(DragonDamagesString, dragonDamages);
    if(parseDamageCount != 5) return 9;

    // Tách tên của người cưởi rồng
    int parseRiderCount = parseRiderNameString(RiderNameString, dragons);
    if(parseRiderCount != N) return 10;

    // for(int i = 0; i < N; i++) {
    //     cout << "Name: " << dragons[i].dragonNames << " " << 
    //     "Type: " << dragons[i].dragonTypes << " " << 
    //     "Damage: " << dragonDamages[dragons[i].dragonTypes - 1] << " " <<
    //     "Temperatement: " << dragons[i].dragonTemperament << " " <<
    //     "Ammo Count: " << dragons[i].ammoCounts << " " <<
    //     "Rider: " << dragons[i].riderNames << endl;
    // }
    // cout << "Total: " << N << endl;

    // 100 + i
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < dragons[i].dragonNames.length(); j++) {
            string name = dragons[i].dragonNames;
            if(name[j] == '@' || name[j] == '!' || name[j] == '#' || name[j] == '$' ||
                name[j] == '%' || name[j] =='^' || name[j] == '&' || name[j] == '*') {
                    return 100 + i;
            }
        }
    }

    // 500 + k
    int specialCharCount = specialCharCountFun(DragonTypeString);
    if(specialCharCount != 0) return 500 + specialCharCount;

    // 900 + i
    for(int i = 0; i < N; i++) {
        for(int j = 1; j < dragons[i].riderNames.length(); j++) {
            string riderName = dragons[i].riderNames;
            if(riderName[j] == ' ' && riderName[j - 1] == ' ') return 900 + i;
        }
    }

    // 1000 + k
    int spaceCountError = spaceCountErrorFun(DragonNameString);
    if(spaceCountError != 0) return 1000 + spaceCountError;

    // Trả về 1 nếu không có lỗi
    return 1;
}

// Task 2
string findKthStrongestDragon(Dragon dragons[], int dragonDamages[5], int N, int T)
{
    // TODO: Implement this function
    float strongestDamage = 0;
    int strongestIdx = -1;

    for(int i = 0; i < N; i++ ) {
        if(dragons[i].dragonTemperament >= T) {
            int power = 0;
            if(dragons[i].dragonTypes == 1) {
                power = (dragons[i].ammoCounts * dragonDamages[0]) + dragons[i].dragonTemperament * 3;
            } else if(dragons[i].dragonTypes == 2) {
                power = (dragons[i].ammoCounts * dragonDamages[1] + dragons[i].dragonTemperament * 2);
            } else if(dragons[i].dragonTypes == 3) {
                power = (dragons[i].ammoCounts * dragonDamages[2] + dragons[i].dragonTemperament);
            } else if(dragons[i].dragonTypes == 4) {
                power = (dragons[i].ammoCounts * dragonDamages[3] + dragons[i].dragonTemperament / 2);
            } else {
                power = (dragons[i].ammoCounts * dragonDamages[4] * 0.9 + dragons[i].dragonTemperament * 1.5);
            }
            if(strongestDamage < power) {
                strongestDamage = power;
                strongestIdx = i;
            }
        }
    }
    
    if(strongestIdx != -1) return dragons[strongestIdx].dragonNames;

    return "None";
}

// Task 3.1
static bool headerPrinted = false;
void printCompatibilityTable(string fighterName, string dragonName, float compatibility)
{   
    if(!headerPrinted) {
        cout << "Warrior      Dragon        Compatibility    Review" << endl;
    }
    headerPrinted = true;

    string result = (compatibility > 4) ? "Compatible" : "Not Compatible";

    cout << left << setw(13) << fighterName
         << setw(14) << dragonName
         << setw(17) << fixed << setprecision(2) << compatibility
         << result << endl;
}

void compatibilityCheck(Dragon dragons[], string warriorName, int warriorSkill)
{
    // TODO: Implement this function
    for(int i = 0; i < N; i++) {
        float compatibility = (10 - abs(dragons[i].dragonTemperament - warriorSkill)) / 2.0;
        printCompatibilityTable(warriorName, dragons[i].dragonNames, compatibility);
    }

    headerPrinted = false;
}

// Task 3.2
void buddyMatching(Dragon dragons[], string warriors[][3])
{
    // TODO: Implement this function
    bool dragonTaken[100] = {false};

    for(int i = 0; i < N; i++) {
        string warriorName = warriors[i][0];
        int warriorSkill = stoi(warriors[i][1]);

        int bestDragonIndex = -1;
        float bestCompatibility = -1;
        for (int j = 0; j < N; j++) {
            if (dragonTaken[j]) continue;

            float compatibility = (10 - abs(dragons[j].dragonTemperament - warriorSkill)) / 2.0;

            if (compatibility > bestCompatibility) {
                bestCompatibility = compatibility;
                bestDragonIndex = j;
            }
        }

        if (bestDragonIndex != -1) {
            dragonTaken[bestDragonIndex] = true;
            printCompatibilityTable(warriorName, dragons[bestDragonIndex].dragonNames, bestCompatibility);
        }
    }
}

// Task 4
void computeChallengeTime(string warriors[][3], int map[10][10])
{
    // TODO: Implement this function
    int warriorTime[5] = {0};

    for(int i = 0; i < N; i++) {
        int warriorID = stoi(warriors[i][2]);

        for(int row = 0; row < 10; row++) {
            for(int col = 0; col < 10; col++) {
                int tileID = (row + col) % 5;
                int itemCode = map[row][col];

                if(tileID == warriorID) {
                    warriorTime[i] += 5;
                    continue;
                }
                    
                if(itemCode == warriorID) {
                    int goTime = (row + col * 2) * 5;
                    int returnTime = abs((row + col * 2) - 1) * 5;
                    warriorTime[i] += goTime + returnTime;
                } else {
                    warriorTime[i] += 5;
                }
            }
        }
    }
   
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (warriorTime[i] > warriorTime[j]) {
                int tempTime = warriorTime[i];
                warriorTime[i] = warriorTime[j];
                warriorTime[j] = tempTime;

                string tempName = warriors[i][0];
                warriors[i][0] = warriors[j][0];
                warriors[j][0] = tempName;
            }
        }
    }

    cout << "Warrior      Total Time (secs)" << endl;
    for(int i = 0; i < 4; i++) {
        cout << left << setw(13) << warriors[i][0] << setw(14) << warriorTime[i] << endl;
    }
}

// Task 5.1
void fighterDamage(Dragon dragons[], string warriors[][3], int teamsDamage[])
{
    // TODO: Implement this function
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(warriors[i][0] == dragons[j].riderNames) {
                int damage = (dragonDamages[dragons[j-1].dragonTypes] * dragons[j].ammoCounts) + (stoi(warriors[i][1]) * 5);
                teamsDamage[i] = damage;
                cout << dragons[j].riderNames <<"-"<< dragons[j].dragonNames << ": damage = " << damage << endl;
            }
        }
    }
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
