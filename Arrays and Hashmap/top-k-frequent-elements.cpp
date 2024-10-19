#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // Using sorting mechanism Time complexity of O(nlogn) + O(n) = O(nlogn)
        // vector<int> res;
        // unordered_map<int,int> umap;
        // int max=0;
        // for(int num:nums){
        //     umap[num]+=1;
        //     if(max<umap[num])
        //         max=umap[num];
        // }

        // vector<pair<int, int>> vec(umap.begin(), umap.end());

        // sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        //     return a.second > b.second;  // Sort by value in descending order
        // });

        // for (auto [key,value] : vec) {
        //     res.push_back(key);
        //     k--;
        //     if(k==0)
        //         break;
        // }
        // return res;

        // Using bucket sort   Time complexity of O(n) + O(n) = O(n)
        vector<int> res;
        unordered_map<int,int> umap;
        unordered_map<int,vector<int> > bucket_srt;
        int max=0;
        for(int num:nums){
            umap[num]+=1;
            if(max<umap[num])
                max=umap[num];
        }
        for(auto [key,value]:umap){
            bucket_srt[value].push_back(key);
        }
        while(k!=0){
            for(int num:bucket_srt[max--]){
                res.push_back(num);
                k--;
            }
        }
        return res;
    }
};

int main(){
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(2);
    int k =2;
    Solution s;
    cout<<"[";
    for(int num:s.topKFrequent(nums,k))
        cout<<num<<",";
    cout<<"]";
}