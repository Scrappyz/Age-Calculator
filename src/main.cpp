#include "main.hpp"
#include "time.hpp"
#include "date.hpp"
#include "age.hpp"

using namespace std;

string Main::program_name;
unordered_map<string, bool> Main::flags = {{"-h", 0}, {"--help", 0}, {"-a", 0}, {"--all", 0},
{"-y", 0}, {"--years", 0}, {"-m", 0}, {"--months", 0},
{"-d", 0}, {"--days", 0}, {"-hh", 0}, {"--hours", 0}, {"-mm", 0}, {"--minutes", 0}, {"-s", 0},
{"--seconds", 0}};
bool Main::has_flags = false;

string Main::getProgramName()
{
    return program_name;
}

bool Main::getFlag(const string& str)
{
    return flags[str];
}

bool Main::hasFlags()
{
    return has_flags;
}

void Main::setProgramName(const string& str)
{
    for(int i = str.size()-1; i >= 0; i--) {
        if(str[i] == '\\' || str[i] == '/') {
            program_name.assign(str.begin()+(i+1), str.end());
            return;
        }
    }
    program_name = str;
}

void Main::printHelp()
{
    cout << "Format:" << endl;
    cout << "  " << program_name << " <OPTIONS> <DATE> <TIME>" << endl;
    cout << "  " << program_name << " <OPTIONS> <PAST_DATE> <PAST_TIME> - <FUTURE_DATE> <FUTURE_TIME>" << endl;
    cout << "Options:" << endl;
    cout << "  -h, --help                           Displays help text" << endl;
    cout << "  -a, --all                            Displays all info" << endl;
    cout << "  -y, --years                          Displays age in years" << endl;
    cout << "  -m, --months                         Displays age in months" << endl;
    cout << "  -d, --days                           Displays age in days" << endl;
    cout << "  -hh, --hours                         Displays age in hours" << endl;
    cout << "  -mm, --minutes                       Displays age in minutes" << endl;
    cout << "  -s, --seconds                        Displays age in seconds" << endl;
}

void Main::setFlags(vector<string>& args)
{
    for(int i = 0; i<args.size(); i++) {
        if(args[i][0] == '-' && args[i].size() > 1) {
            if(flags.find(args[i]) != flags.end()) {
                flags[args[i]] = true;
                has_flags = true;
                args.erase(args.begin()+i);
                i--;
            } else {
                cerr << "[Invalid Argument]: " << args[i] << endl;
                cerr << "[Use '-h' flag to get help]" << endl;
                exit(EXIT_FAILURE);
            }
        }
    }
}

int main(int argc, char* argv[])
{
    Main::setProgramName(argv[0]);
    vector<string> args;
    args.assign(argv+1, argv+argc);

    if(args.size() > 0) { // cmd mode
        Main::setFlags(args);
        if(Main::getFlag("-h") || Main::getFlag("--help")) {
            Main::printHelp();
            return 0;
        }

        Age age;
        Date past, present;
        past.setDate(args);
        if(!args.empty())
            present.setDate(args);
        else
            present.setDateToday();

        if(past.isValidDate() && present.isValidDate()) {
            cout << "Past date: ";
            past.printDate();
            cout << "Future date: ";
            present.printDate();
        } else {
            cerr << "[Invalid Date]" << endl;
            return 0;
        }
        if(past.isValidDate() && present.isValidDate() && past < present) {
                age.setAge(past, present);
                age.printAge();
        } else {
            cerr << "[Invalid Date]" << endl;
            return 0;
        }
    }
    return 0;
}
