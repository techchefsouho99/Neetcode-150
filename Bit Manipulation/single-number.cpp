class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // unordered_map<int,int> umap;
        // for(int num:nums)
        //     umap[num]+=1;
        // for(auto [key,value] : umap){
        //     if(value == 1)
        //         return key;
        // }
        // return nums[0];

        // A XOR a returns 0, so returns 0 for all except the unique one
        int result = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            result = result ^ nums[i];
        }
        
        return result;
    }
};