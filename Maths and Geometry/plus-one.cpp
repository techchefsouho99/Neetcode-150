class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        vector<int> finArr;
        int arrLen = digits.size();
        for(int i = 0 ; i < arrLen ; i++){
            int sum = digits[arrLen - 1 - i] + carry;
            finArr.push_back(sum%10);
            carry = sum > 9 ? 1 : 0;
        }
        if(carry > 0)
            finArr.push_back(1);
        reverse(finArr.begin(),finArr.end());
        return finArr;
    }
};