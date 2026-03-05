#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

string s;
size_t i;

bool S();
bool E();
bool T();
bool F();
bool I();
bool D();

int main() {
    ifstream fin("input.txt");
    if (!fin.is_open()) {
        cout << "Error: input.txt not found. Please make sure the file exists in the program directory." << endl;
        return 1;
    }

    string line;
    while (getline(fin, line)) {
        s = line;
        i = 0;
        if (S() && i == s.length()) {
            cout << "The string \"" << line << "\" is in the language." << endl;
        } else {
            cout << "The string \"" << line << "\" is not in the language." << endl;
        }
    }

    fin.close();
    return 0;
}

bool S() {
    size_t savedI = i;
    if (I()) {
        if (i < s.length() && s[i] == '=') {
            ++i;
            if (E()) {
                return true;
            }
        }
    }
    i = savedI;
    return false;
}

bool E() {
    if (T()) {
        if (i < s.length() && (s[i] == '+' || s[i] == '-')) {
            ++i;
            return E();
        }
        return true;
    }
    return false;
}

bool T() {
    if (F()) {
        if (i < s.length() && (s[i] == '*' || s[i] == '/')) {
            ++i;
            return T();
        }
        return true;
    }
    return false;
}

bool F() {
    if (I() || D()) {
        return true;
    } else if (i < s.length() && s[i] == '(') {
        ++i;
        if (E() && i < s.length() && s[i] == ')') {
            ++i;
            return true;
        }
    }
    return false;
}

bool I() {
    if (i < s.length() && islower(s[i])) {
        ++i;
        while (i < s.length() && islower(s[i])) {
            ++i;
        }
        return true;
    }
    return false;
}

bool D() {
    size_t start = i;
    while (i < s.length() && isdigit(s[i])) {
        ++i;
    }
    return i > start;
}
