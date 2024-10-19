/*
* Two Sum : https://leetcode.com/problems/two-sum/description/
*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> umap;
        for(int i=0;i<nums.size();i++){
            if(umap.find(target - nums[i])!=umap.end())
                return {umap[target-nums[i]],i};
            umap[nums[i]]=i;
        }
        return {};
    }
};

int main(){
    vector<int> nums;
    nums.push_back(11);
    nums.push_back(7);
    nums.push_back(10);
    nums.push_back(2);

    int target = 9;

    Solution s;

    cout<<"[";
    for(int i = 0; i<s.twoSum(nums,target).size(); i++){
        cout << s.twoSum(nums,target)[i];
        if(i < 1) 
            cout<<",";
    }
    cout<<"]";
}