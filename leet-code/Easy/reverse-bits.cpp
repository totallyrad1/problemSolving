class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        string res = "";
        int result = 0;
        while(n){
            int bit = n % 2;
            res.push_back(bit + '0');
            n /= 2;
        }
        while(res.size() < 32){
            res.push_back('0');
        }
        return std::stol(res, nullptr, (uint32_t)2);
    }
};