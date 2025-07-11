class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int rest = 0;
        string res = "";
        while(i >= 0 || j >=0){
            if(i >= 0 && j >=0){
                int n1 = num1[i] - '0';
                int n2 = num2[j] -'0';
                int val = n1 + n2 + rest;
                // cout << val << " " << n1 << " " << n2 << " " << rest << endl;
                res.insert(res.begin(), (val % 10) + '0');
                rest = val / 10;
                i--;
                j--;
            }else if(i >= 0){
                if(rest){
                    int n = num1[i] - '0';
                    int val = rest + n;
                    // cout << val << " " << rest << " " << n << endl;
                    res.insert(res.begin(),(val % 10) + '0');
                    rest = val / 10;
                }else{
                    res.insert(res.begin(), num1[i]);
                }
                i--;
            }else if(j >= 0){
                if(rest){
                    int n = num2[j] - '0';
                    int val = rest + n;
                    // cout << val << " " << rest << " " << n << endl;
                    res.insert(res.begin(), (val % 10) + '0');
                    rest = val / 10;
                }else{
                    res.insert(res.begin(), num2[j]);
                }
                j--;
            }
        }
        if(rest) res.insert(res.begin(), rest + '0');

        return res;
    }
};