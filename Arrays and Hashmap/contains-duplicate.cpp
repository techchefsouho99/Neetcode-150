#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> uset;
        for(int num : nums){
            if(uset.find(num) != uset.end())
                return true;
            uset.insert(num);
        }
        return false;
    }
};

int main() {
    Solution sol;

    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(1);

    if(sol.containsDuplicate(nums)) {
        cout << "Duplicate found!" << endl;
    } else {
        cout << "No duplicates!" << endl;
    }

    return 0;
}