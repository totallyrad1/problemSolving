class Solution {
public:

    int getValue(char c){
        if(c == 'I')    return 1;
        if(c == 'V')    return 5;
        if(c == 'X')    return 10;
        if(c == 'L')    return 50;
        if(c == 'C')    return 100;
        if(c == 'D')    return 500;
        if(c == 'M')    return 1000;
        return 0;
    }
    int romanToInt(string s) {
        int i = 0 ;
        int sum = 0;
        while(i < s.size()){
            if(i + 1 < s.size()){
                int val1, val2;
                val1 = getValue(s[i]);
                val2 = getValue(s[i + 1]);
                if(val2 > val1){
                    sum += (val2 - val1);
                    i+=2;
                }else{
                    sum += val1;
                    i++;
                }
            }else{
                sum += getValue(s[i]);
                i++;
            }
        }
        return sum;
    }
};