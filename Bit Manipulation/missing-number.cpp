class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int> res(nums.size()+1,-1);
        for(int num : nums){
            res[num]=num;
        }
        for(int i=0;i<res.size();i++){
            if(res[i]==-1)
                return i; 
        }
        return 0;
    }
};