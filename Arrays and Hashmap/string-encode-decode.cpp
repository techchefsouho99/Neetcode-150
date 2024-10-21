#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for(string s : strs){
            res += to_string(s.length()) + "#" + s;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i=0;
        int j=0;
        while (i < s.length()) {
            // The number can be more than 10 or 99
            j=i;
            while(s[j]!='#')
                j++;
            int len = stoi(s.substr(i,j+1));
            res.push_back(s.substr(j+1,len));
            i = j + (len + 1);
        }
        return res;
    }
};

int main(){
    vector<string> strs;
    strs.push_back("we");
    strs.push_back("say");
    strs.push_back(":");
    strs.push_back("yes");
    strs.push_back("!@#$%^&*()");

    Solution sol;
    
    string eStr = sol.encode(strs);
    vector<string> dStrLst = sol.decode(eStr);
    for(string s : dStrLst){
        cout<<s<<" ";
    }
    return 0;

}
