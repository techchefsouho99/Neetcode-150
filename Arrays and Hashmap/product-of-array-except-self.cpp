/*
* Product Of Array Except Self : https://leetcode.com/problems/product-of-array-except-self/description/
*/
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int arrLen = nums.size();
        vector<int> prefix(arrLen,1);
        vector<int> suffix(arrLen,1);
        vector<int> res;
        int pProd = 1;
        int sProd = 1;
        for(int i=0; i<arrLen; i++){
            pProd*=nums[i];
            sProd*=nums[arrLen-1-i];
            prefix[i]=pProd;
            suffix[arrLen - 1 - i] = sProd;
        }
        for(int i=0; i<arrLen; i++){
            if(i==0)
                res.push_back(suffix[i+1]);
            else if(i == arrLen - 1)
                res.push_back(prefix[i-1]);
            else
                res.push_back(prefix[i-1] * suffix[i+1]);
        }
        return res;
    }
};

int main(){
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    Solution s;
    for(int i:s.productExceptSelf(nums))
        cout<<i;
    return 0;
}