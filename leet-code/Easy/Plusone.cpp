#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        len--;
        while(len > 0){
            if(digits[len] == 9){
                digits[len] = 0;
                len--;
            }else{
                digits[len] += 1;
                return digits;
            }
        }
        if(digits[0] == 9){
            digits[0] = 0;
            digits.insert(digits.begin(), 1);
        }else{
            digits[0] += 1;
        }
        return digits;
    }
};

int main(){
    Solution d;
    vector<int> digits = {9,9,9,9};
    d.plusOne(digits);
    for(auto &digit: digits){
        cout << digit << " ";
    }
    cout << endl;
}