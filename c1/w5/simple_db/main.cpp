#include <map>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>
#include <iomanip>
#include <iostream>
#include <exception>
using namespace std;


struct Year {
    explicit Year(int new_value) {
        value = new_value;
    }
    int value;
};

struct Month {
    explicit Month(int new_value) {
        value = new_value;
    }
    int value;
};

struct Day {
    explicit Day(int new_value) {
        value = new_value;
    }
    int value;
};


struct Date {
    Date() {
        year = 0;
        month = 0;
        day = 0;
    }
    explicit Date(Year new_year, Month new_month, Day new_day) {
        if (new_month.value < 1 || new_month.value > 12) { 
            throw runtime_error("Month value is invalid: " + to_string(new_month.value));
        }
        else if (new_day.value < 1 || new_day.value > 31) { 
            throw runtime_error("Day value is invalid: " + to_string(new_day.value));
        } 
        year = new_year.value;
        month = new_month.value;
        day = new_day.value;
    }
    int year;
    int month;
    int day;
};

ostream& operator<<(ostream& stream, const Date& date) {
    stream << setw(4) << setfill('0') << date.year << '-'
           << setw(2) << setfill('0') << date.month << '-'
           << setw(2) << setfill('0') << date.day;
    return stream;
}

void EnsureSlashAndIgnore(istream& stream) {
    if (stream.peek() != '-') {
        stringstream stream;
        stream << "Divider != -\tIt's " << stream.peek();
        throw runtime_error(stream.str());
    }
    stream.ignore(1);
}

istream& operator>>(istream& stream, Date& date) {
    int year_value;
    int month_value;
    int day_value;
    stream >> year_value;
    EnsureSlashAndIgnore(stream);
    stream >> month_value;
    EnsureSlashAndIgnore(stream);
    stream >> day_value;
    Year year = Year(year_value);
    Month month = Month(month_value);
    Day day = Day(day_value);
    date = Date(year, month, day);
    return stream;
}

bool operator<(const Date& leftDate, const Date& rightDate) {
    if (leftDate.year != rightDate.year) {
        return leftDate.year < rightDate.year;
    }
    else if (leftDate.month != rightDate.month) {
        return leftDate.month != rightDate.month;
    }
    else {
        return leftDate.day < rightDate.day;
    }
}


struct Event { 
    string description;
};

ostream& operator<<(ostream& stream, const Event& event) {
    stream << event.description;
    return stream;
}

istream& operator>>(istream& stream, Event& event) {
    stream >> event.description;
    return stream;
}

bool operator<(const Event& leftEvent, const Event& rightEvent) {
    return leftEvent.description < rightEvent.description;
}

class Database {
public:
    void AddEvent(const Date& date, const string& description) {
        if (events.count(date) == 0) {
            events[date] = {};
        } 
        else {
            for (int i = 0; i < events[date].size(); i++) {
                if (events[date][i].description == description) {
                    return;
                } 
            }
        }
        events[date].push_back(Event{description});
    }

    void DelEvent(const Date& date, const string& description) {
        if (events.count(date) == 0) {
            cout << "Event not found" << endl;
        } 
        for (int i = 0; i < events[date].size(); i++) {
            if (events[date][i].description == description) {
                events[date].erase(events[date].begin() + i);
                cout << "Deleted successfully" << endl;
                return;
            }
        }
        cout << "Event not found" << endl;
    }

    void DelDate(const Date& date) {
        int n = 0;
        if (events.count(date) != 0) {
            n = events[date].size();
            events.erase(date);
        }
        cout << "Deleted " << n << " events" << endl;
    }

    void Find(const Date& date) {
        if (events.count(date) == 0) {
            return;
        }
        sort(begin(events[date]), end(events[date]));
        bool is_first = true;
        for (auto elem : events[date]) {
            if (is_first) {
                cout << elem.description;
                is_first = false;
                continue;
            }
            cout <<  " " << elem.description;
        }
        cout << endl;
    }

    void Print() {
        for (auto row : events) {
            Date date = row.first;
            vector<Event> events_ = row.second;
            for (auto event : events_) {
                cout << date << ' ' << event << endl;
            }
        }
    }
private:
    map<Date, vector<Event>> events;
};

int main() {
    Database db = Database();
    try{
        while (true) {
        string command;
        cin >> command;
            if (command == "Add") {
                try{
                    Date date;
                    cin >> date;
                    string description;
                    cin >> description;
                    db.AddEvent(date, description);
                } catch(exception& ex) {
                    cout << ex.what() << endl;
                }
            }
            else if (command == "Del") {
                Date date;
                cin >> date;
                if (cin.peek() == '\n') {
                    db.DelDate(date);
                }
                else {
                    string description;
                    cin >> description;
                    db.DelEvent(date, description);
                }
            }
            else if (command == "Find") {
                Date date;
                cin >> date;
                db.Find(date);
            }
            else if (command == "Print") {
                db.Print();
            }
            else if (command == "Stop") {
                break;
            }
        }
    } catch(exception& ex) {
        return 1;
    }
    return 0;
}
