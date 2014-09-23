class Solution {
public:
    string multiply(string num1, string num2) {
        int l1 = num1.length(), l2 = num2.length(), l3 = l1 + l2;
        string ret(l3, '0');
        for(int i = l1 - 1; i >= 0; -- i)
            for(int j = l2 - 1; j >= 0; -- j) {
                int k = i + j + 1;
                int t = (num1[i] - '0') * (num2[j] - '0') + ret[k] - '0';
                ret[k] = t % 10 + '0';
                ret[k - 1] += t / 10;
            }
        for(int i = 0; i < l3; ++ i)
            if(ret[i] != '0')
                return ret.substr(i, l3 - i);
        return "0";
    }
};