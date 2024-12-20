class Solution {
public:
    vector<int> countBits(int n) {
        if(n==0)
            return {0};
        vector<int> res = {0,1};
        // iterative method
        // for(int i=2;i<=n;i++){
        //     int dividend = i;
        //     int count=0;
        //     while(dividend!=1){
        //         int rem = dividend % 2;
        //         dividend/=2;
        //         if(rem == 1)
        //             count++;
        //     }
        //     res.push_back(++count);
        // }

        // better solution bit numbers are in cyclic order
        for(int i=2;i<=n;i++){
            if(i%2==0)
                res.push_back(res[i/2]);
            else
                res.push_back(res[i/2]+1);
        }
        return res;
    }
};