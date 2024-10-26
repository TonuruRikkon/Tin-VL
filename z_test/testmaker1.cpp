#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void generateTestFile(const string& filename, const string& S, const string& T) {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        outFile << S << endl;
        outFile << T << endl;
        outFile.close();
    } else {
        cerr << "Unable to open file";
    }
}

string generateRandomString(size_t length) {
    string str;
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const size_t max_index = sizeof(charset) - 1;
    for (size_t i = 0; i < length; ++i) {
        str += charset[rand() % max_index];
    }
    return str;
}

int main() {
    srand(time(0));

    // Generate strings S and T with length 1e6
    string S = generateRandomString(1e6);
    string T = generateRandomString(1e6);

    // Write to file
    generateTestFile("cstring.inp", S, T);

    return 0;
}
