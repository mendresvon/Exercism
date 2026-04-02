#include <string>
#include <iostream>

using namespace std;
namespace log_line {
std::string message(std::string line) {
    int start = line.find(": ");
    std::string error{line.substr(start+2)};
    return error;
}

std::string log_level(std::string line) {
    // return the log level
    int start = line.find("[");
    cout << "start: " << start << endl;
    int end = line.find("]");
    cout << "end: " << end << endl;
    std::string lvl{line.substr(start + 1, end - 1)};
    return lvl;
}

std::string reformat(std::string line) {
    // return the reformatted message
    int msg_start = line.find(": ");
    std::string msg{line.substr(msg_start + 2)};

    int err_start = line.find("[");
    int err_end = line.find("]");
    std::string lvl{line.substr(err_start + 1, err_end - 1)};
    return msg + " (" + lvl + ")";
    
}
}  // namespace log_line
