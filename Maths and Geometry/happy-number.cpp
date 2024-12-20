class Solution {
public:
    int newNum(int n){
        int sum=0;
        while(n!=0){
            int rem = n % 10;
            sum += rem*rem;
            n/=10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> uset; 
        while (n != 1 && uset.find(n) == uset.end()) {
            uset.insert(n);
            n = newNum(n);
            
        }
        
        return n == 1;
    }
};