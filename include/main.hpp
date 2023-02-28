#ifndef MAIN_HPP_INCLUDED
#define MAIN_HPP_INCLUDED

#include <iostream>
#include <vector>
#include <chrono>
#include <unordered_map>
#include <sstream>
#include <cctype>

using namespace std;

class Main {
private:
    static string program_name;
    static unordered_map<string, bool> flags;
    static bool has_flags;
    Main(); // prevents creating an instance of the class
public:
    static void setProgramName(const string&);
    static void setFlags(vector<string>&);

    static string getProgramName();
    static bool getFlag(const string&);
    static bool hasFlags();

    static void printHelp();
};

#endif // MAIN_HPP_INCLUDED
