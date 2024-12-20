class Solution {
public:
    int hammingWeight(int n) {
        int dividend = n;
        int count = 0;
        while(dividend != 1){
            int rem = dividend % 2;
            dividend/=2;
            if(rem == 1)
                count++;
        }
        return ++count;
    }
};