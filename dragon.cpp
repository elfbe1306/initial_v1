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
    if(parseTemperamentCount != N) return 8;

    // Tách sát thương của các loại rồng
    int parseDamageCount = parseDragonDamageString(DragonDamagesString, dragonDamages);
    if(parseDamageCount != N) return 9;

    // Tách tên của người cưởi rồng
    int parseRiderCount = parseRiderNameString(RiderNameString, dragons);
    if(parseRiderCount != N) return 10;

    for(int i = 0; i < 5; i++) {
        cout << "Name: " << dragons[i].dragonNames << " " << 
        "Type: " << dragons[i].dragonTypes << " " << 
        "Damage: " << dragonDamages[i] << " " <<
        "Temperatement: " << dragons[i].dragonTemperament << " " <<
        "Ammo Count: " << dragons[i].ammoCounts << " " <<
        "Rider: " << dragons[i].riderNames << endl;
    }
    cout << "Total: " << N << endl;

    // Trả về 1 nếu không có lỗi
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
