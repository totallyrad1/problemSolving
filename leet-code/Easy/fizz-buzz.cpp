class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        int i = 1;
        while(i <= n){
            if(i % 3 == 0 && i % 5 == 0){
                res.push_back("FizzBuzz");
            }else if(i % 5 ==0){
                res.push_back("Buzz");
            }else if(i % 3 ==0){
                res.push_back("Fizz");
            }else{
                res.push_back(to_string(i));
            }
            i++;
        }
        return res;
    }
};