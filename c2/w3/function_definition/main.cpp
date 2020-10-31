#include <iostream>
#include "sum_reverse_sort.h"

int main() {
    cout << Sum(1, 2) << endl;
    vector<int> nums = {1, 9, 8, 2, 4, 6};
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << ' ';
    }
    cout << endl;
    Sort(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << ' ';
    }
    cout << endl;
    string s = "argentinamanitnegra";
    cout << Reverse(s) << endl;
}