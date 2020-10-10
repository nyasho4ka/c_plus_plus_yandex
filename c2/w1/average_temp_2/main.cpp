#include <iostream>
#include <vector>
using namespace std;


vector<int> GetObservationsFromInput() {
    int num_of_observations;
    int current_observation;
    vector<int> observations;

    cin >> num_of_observations;
    for (size_t i = 0; i < num_of_observations; i++) {
        cin >> current_observation;
        observations.push_back(current_observation);
    }
    return observations;
}

int CalculateAverage(const vector<int>& observations) {
    int sum = 0;
    for (size_t i = 0; i < observations.size(); i++) {
        sum += observations[i];
    }
    return sum / static_cast<int>(observations.size());
}

vector<int> GetIndicesGTAvg(const vector<int>& observations, int& average) {
    vector<int> indices_gt_avg;
    for (size_t i = 0; i < observations.size(); i++) {
        if (observations[i] > average) {
            indices_gt_avg.push_back(i);
        }
    }
    return indices_gt_avg;
}

void PrintIndices(const vector<int>& indices) {
    cout << indices.size() << endl;
    for (auto elem : indices) {
        cout << elem << ' ';
    }
}

int main() {
    vector<int> observations = GetObservationsFromInput();
    int average = CalculateAverage(observations);
    vector<int> indices_gt_avg = GetIndicesGTAvg(observations, average);
    PrintIndices(indices_gt_avg);
    return 0;
}