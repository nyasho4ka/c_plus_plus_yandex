#include <vector>
#include <iostream>
#include <string>
#include <tuple>
#include <map>
using namespace std;


enum class Lang {
    DE, FR, IT
};


struct Region {
  string std_name;
  string parent_std_name;
  map<Lang, string> names;
  int64_t population;
};


bool operator<(const Region& lhs, const Region& rhs) {
    return tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population) 
        < tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
}

bool comp(const pair<string, int>& lhs, const pair<string, int>& rhs) {
    return lhs.second < rhs.second;
}

int FindMaxRepetitionCount(const vector<Region>& regions) {
    // Составить отображение региона в его количество
    int max_count = 0;
    map<Region, int> region_counts;
    for (auto region : regions) {
        if (region_counts.count(region) == 0) {
            region_counts[region] = 0;
        }
        region_counts[region] += 1;
        max_count = max_count > region_counts[region] ? max_count : region_counts[region];
    }
}

int main() {
    vector<Region> regions_one = {
        {
            "Moscow",
            "Russia",
            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
            89
        }, {
            "Russia",
            "Eurasia",
            {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
            89
        }, {
            "Moscow",
            "Russia",
            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
            89
        }, {
            "Moscow",
            "Russia",
            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
            89
        }, {
            "Russia",
            "Eurasia",
            {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
            89
        },
    };
    cout << FindMaxRepetitionCount(regions_one) << endl;
    regions_one = {
        {
            "Moscow",
            "Russia",
            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
            89
        }, {
            "Russia",
            "Eurasia",
            {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
            89
        }, {
            "Moscow",
            "Russia",
            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
            89
        }, {
            "Moscow",
            "Toulouse",
            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
            89
        }, {
            "Moscow",
            "Russia",
            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
            31
        },
    };
    cout << FindMaxRepetitionCount(regions_one) << endl;
    return 0;
}