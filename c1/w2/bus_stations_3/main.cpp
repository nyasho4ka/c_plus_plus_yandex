#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

int GetRequestsNumber()
{
    int Q;
    cin >> Q;
    return Q;
}

set<string> ReadStops(int stops_count);

void ReadRequests(int Q)
{   
    int route_counter = 1;
    map<set<string>, int> route_number;
    int stops_count;
    for (int i = 0; i < Q; i++){
        cin >> stops_count;
        auto stops = ReadStops(stops_count);
        if (route_number.count(stops) == 0)
        {
            cout << "New bus " << route_counter << endl;
            route_number[stops] = route_counter;
            route_counter++;
            continue;
        }
        cout << "Already exists for " << route_number[stops] << endl;
    }
}

set<string> ReadStops(int stops_count)
{
    set<string> stops;
    for (int i = 0; i < stops_count; i++)
    {
        string stop;
        cin >> stop;
        stops.insert(stop);
    }
    return stops;
}

int main()
{
    int Q = GetRequestsNumber();
    ReadRequests(Q);
}