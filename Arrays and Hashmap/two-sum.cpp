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
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            if(umap.find(target - nums[i])!=umap.end()){
                res.push_back(umap[target-nums[i]]);
                res.push_back(i);
                break;
            }
            umap[nums[i]]=i;
        }
        return res;
    }
};

int main(){
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);

    int target = 9;

    Solution s;
    cout<<"[";
    for(int res : s.twoSum(nums,target))
        cout << res <<",";
    cout<<"]";
}