class Solution {
public:
    string addBinary(string a, string b) {
        if(a.length() < b.length()) {
            string temp = a;
            a = b;
            b = temp;
        }
        
        string temp(a.length() - b.length() + 1, '0');
        a = '0' + a;
        b = temp + b;
        for(int i = a.length() - 1; i >= 1; -- i) {
            a[i - 1] += (a[i] - '0' + b[i] - '0') / 2;
            a[i] = (a[i] - '0' + b[i] - '0') % 2 + '0';
        }
        int index = 0;
        for(index = 0; index < a.length() - 1; ++ index)
            if(a[index] != '0')
                break;
        string sum = "";
        for(int i = index; i < a.length(); ++ i)
            sum += a[i];
        return sum;
    }
};