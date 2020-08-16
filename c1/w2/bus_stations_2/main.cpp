#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;


int GetRequestsNumber()
{
    int Q;
    cin >> Q;
    return Q;
}

vector<string> ReadStops(int stops_count);

void ReadRequests(int Q)
{   
    int route_counter = 1;
    map<vector<string>, int> route_number;
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

vector<string> ReadStops(int stops_count)
{
    vector<string> stops(stops_count);
    for (int i = 0; i < stops_count; i++)
    {
        cin >> stops[i];
    }
    return stops;
}

int main()
{
    int Q = GetRequestsNumber();
    ReadRequests(Q);
}