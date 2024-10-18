/*
* 242. Valid Anagrams: https://leetcode.com/problems/valid-anagram/description/
*/
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(t.length()!=s.length())
            return false;
        unordered_map<char,int> umap;
        for(char ch : s){
                umap[ch]+=1;
        }
        for(char ch:t){
            if(umap[ch]==0)
                return false;
            umap[ch]-=1;
        }
        return true;
    }
};

int main(){
    string s = "cat";
    string t = "tac";
    Solution sol;
    if(sol.isAnagram(s,t))
        cout << "Two strings are anagram";
    else
        cout << "Two strings are not anagram";
    return 0;
}