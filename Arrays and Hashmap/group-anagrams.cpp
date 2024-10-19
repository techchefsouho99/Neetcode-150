/*
* Group Anagrams: https://leetcode.com/problems/group-anagrams/description/
*/
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:

    /********************************************    Brute force O(n^2)    ********************************************/ 
    // bool isAnagram(string s,string t){
    //     unordered_map<char,int> umap;
    //     if(s.length()!=t.length())
    //         return false;
    //     for(int i=0; i<s.length(); i++){
    //         umap[s[i]]++;
    //     }
    //     for(char ch:t){
    //         if(umap[ch]==0)
    //             return false;
    //         umap[ch]--;
    //     }
    //     return true;
    // }
    // vector<vector<string>> groupAnagrams(vector<string>& strs) {
    //     vector<vector<string>> res;
    //     unordered_set<int> uset;
    //     for(int i=0; i<strs.size()-1; i++){
    //         if(uset.find(i)==uset.end()){
    //             uset.insert(i);
    //             vector<string> temp;
    //             for(int j=i+1; j<strs.size(); j++){
    //                 if(isAnagram(strs[i],strs[j])){
    //                     uset.insert(j);
    //                     temp.push_back(strs[j]);
    //                 }  
    //             }
    //             temp.push_back(strs[i]);
    //             res.push_back(temp);
    //         }
    //     }
    //     if(uset.find(strs.size()-1)==uset.end()){
    //         vector<string> temp;
    //         temp.push_back(strs[strs.size()-1]);
    //         res.push_back(temp);
    //     }
    //     return res;
    // }

    // using hashmap and iteration
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        /********************************** Time complexity of O(m*n*26)  *********************************/
        vector<vector<string> > res;
        unordered_map<string,vector<string> > umap;
        for(string str:strs){
            vector<int> countArr(26,0);
            string s="";
            for(char ch: str)
                countArr[ch-'a']++;
            for(int count: countArr){
                s+= char(count + 'a');
                s+=to_string(count);
            }
            umap[s].push_back(str);
        }
        for(auto [key,value]:umap)
            res.push_back(value);
        return res;
    }

        // Using sorting
        /********************************** Time complexity of O(m*n*logn)  *********************************/
        // unordered_map<string, vector<string>> mp;
        
        // for(auto x: strs){
        //     string word = x;
        //     sort(word.begin(), word.end());
        //     mp[word].push_back(x);
        // }
        
        // vector<vector<string>> ans;
        // for(auto x: mp){
        //     ans.push_back(x.second);
        // }
        // return ans;
};

int main(){
    vector<string> strs;

    strs.push_back("eat");
    strs.push_back("tea");
    strs.push_back("tan");
    strs.push_back("ate");
    strs.push_back("nat");
    strs.push_back("bat");

    Solution s;
    cout<<"[";
    for(vector<string> strArr : s.groupAnagrams(strs)){
        cout<<"[";
        for(string str : strArr){
            cout<<str<<",";
        }
        cout<<"]";
    }
    cout<<"]";
}