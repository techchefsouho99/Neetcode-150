/*
* Longest Consecutive Sequence: https://leetcode.com/problems/longest-consecutive-sequence/description/
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uset;
        for(int num:nums)
            uset.insert(num);
        int count=0;
        int longest=0;
        int i=0;
        for(auto num: uset){
            count=1;
            if(!(uset.find(num - 1) != uset.end())){
                int j = num + 1;
                while(uset.find(j++) != uset.end())
                    count++;
                longest = max(count,longest);
            }
        }
        return longest;
    }
};

int main(){
    Solution s;
    return 0;
}