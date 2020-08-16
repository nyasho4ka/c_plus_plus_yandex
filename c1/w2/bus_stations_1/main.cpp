#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

map<string, vector<string>> bus_to_stops;

int GetNumberOfRequests()
{
    int Q;
    cin >> Q;
    return Q;
}

void NewBus(string bus, vector<string> stops);
void ReadStops(int stop_count, vector<string>& stops);
void BusesForStop(string stop);
void StopsForBus(string bus);
void AllBuses();

void ReadRequests(int Q)
{   
    string request;
    for (int i = 0; i < Q; i++)
    {
        cin >> request;
        if (request == "NEW_BUS")
        {
            string bus;
            int stop_count;
            cin >> bus >> stop_count;
            vector<string> stops(stop_count);
            ReadStops(stop_count, stops);
            NewBus(bus, stops);
        }
        else if (request == "BUSES_FOR_STOP")
        {
            string stop;
            cin >> stop;
            BusesForStop(stop);
        }
        else if (request == "STOPS_FOR_BUS")
        {
            string bus;
            cin >> bus;
            StopsForBus(bus);
        }
        else if (request == "ALL_BUSES")
        {
            AllBuses();
        }
    }
}

void ReadStops(int stop_count, vector<string>& stops)
{   
    string stop;
    for (int i = 0; i < stop_count; i++) 
    {
        cin >> stop;
        stops[i] = stop;
    }
}

void NewBus(string bus, vector<string> stops)
{
    bus_to_stops[bus] = stops;
}

map<string, vector<string>> InvertBusToStops(map<string, vector<string>>& bus_to_stops)
{
    map<string, vector<string>> stop_to_buses;
    // Пройдемся по всем автобусам
    for (auto item : bus_to_stops)
    {
        string bus = item.first;
        vector<string> stops = item.second;
        // Для каждого автобуса итерируемся по списку его остановок
        for (auto stop : stops)
        {
            // Для каждой остановки добавляем автобус
            stop_to_buses[stop].push_back(bus);
        }
    }
    return stop_to_buses;
}

void PrintVector(vector<string>& vec)
{
    for (auto elem : vec)
    {
        cout << elem << ' ';
    }
    cout << endl;
}

void BusesForStop(string stop)
{
    auto stop_to_buses = InvertBusToStops(bus_to_stops);
    if (stop_to_buses.count(stop) == 0)
    {
        cout << "No stop" << endl;
        return;
    }
    PrintVector(stop_to_buses[stop]);
}

void StopsForBus(string bus)
{   
    if (bus_to_stops.count(bus) == 0)
    {
        cout << "No bus" << endl;
        return;
    }
    map<string, vector<string>> stop_to_buses = InvertBusToStops(bus_to_stops);
    for (auto stop : bus_to_stops[bus])
    {   
        vector<string> buses = stop_to_buses[stop];
        cout << "Stop " << stop << ": ";
        if (buses.size() == 1)
        {
            cout << "no interchange" << endl;
            continue;
        }
        for (auto bus : buses)
        {
            cout << bus << " ";
        }
        cout << endl;
    }
}

void AllBuses()
{
    if (bus_to_stops.size() == 0)
    {
        cout << "No buses" << endl;
        return;
    }
    for (auto item : bus_to_stops)
    {
        string bus = item.first;
        vector<string> stops = item.second;
        cout << "Bus " << bus << " ";
        PrintVector(bus_to_stops[bus]);
    }

}



int main()
{
    int Q = GetNumberOfRequests();
    ReadRequests(Q);
    return 0;
}