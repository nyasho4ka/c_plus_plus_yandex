#include <string>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>
#include <exception>
#include <system_error>
#include <stdlib.h>
using namespace std;


string AskTimeServer() {
    int rand_number = rand() % 3 - 1;

    if (rand_number == 0) {
        stringstream stream;
        stream << setw(2) << setfill('0') << rand() % 24 << ':'
               << setw(2) << setfill('0') << rand() % 60 << ':'
               << setw(2) << setfill('0') << rand() % 60;
        return stream.str(); 
    }
    else if (rand_number == 1) {
        throw system_error(error_code());
    }
    else if (rand_number == 2) {
        throw exception();
    }
}

class TimeServer {
public:
    string GetCurrentTime() {
        try {
            string answer = AskTimeServer();
            last_fetched_time = answer;
            return answer;
        } catch(system_error& err) {
            return last_fetched_time;
        }
    }
private:
    string last_fetched_time = "00:00:00";
};


int main() {
    TimeServer timeServer = TimeServer();
    for (int i = 0; i < 5; i++) {
        try{
            cout << "Current time is " << timeServer.GetCurrentTime() << endl;
        } catch(exception& ex) {
            cout << "Unexcepted exception! " << endl;
        }
    }
    return 0;
}