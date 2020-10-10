#include <iostream>
#include <vector>
using namespace std;


vector<vector<int>> GetBlocksSizes(const int& num_of_blocks) {
    vector<vector<int>> blocks_size;
    for (int i = 0; i < num_of_blocks; i++) {
        int W, H, D;
        cin >> W >> H >> D;
        blocks_size.push_back({});
        blocks_size[i].push_back(W);
        blocks_size[i].push_back(H);
        blocks_size[i].push_back(D);
    }
    return blocks_size;
}

vector<int> GetBlocksVolume(const vector<vector<int>>& blocks_sizes) {
    vector<int> blocks_volume;
    for (auto block_size : blocks_sizes) {
        blocks_volume.push_back(block_size[0] * block_size[1] * block_size[2]);
    }
    return blocks_volume;
}

int CalculateBlocksMass(const vector<int>& blocks_volume, int& density) {
    int blocks_mass = 0;
    for (auto volume : blocks_volume) {
        blocks_mass += volume * density;
    }
    return blocks_mass;
}

int main() {
    int num_of_blocks;
    int density;
    // Get num of blocks
    // Get density value
    cin >> num_of_blocks >> density;
    // Get blocks' sizes
    vector<vector<int>> blocks_sizes = GetBlocksSizes(num_of_blocks);
    // Calculate blocks volume 
    vector<int> blocks_volume = GetBlocksVolume(blocks_sizes);
    // Calculate mass
    int blocks_mass = CalculateBlocksMass(blocks_volume, density);
    cout << blocks_mass << endl;
    return 0;
}