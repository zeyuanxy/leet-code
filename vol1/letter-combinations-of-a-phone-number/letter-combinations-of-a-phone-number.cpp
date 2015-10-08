class Solution {
public:
    vector<char> getCharSet(char number) {
        vector<char> charSet;
        switch(number) {
            case '2':
                charSet.push_back('a');
                charSet.push_back('b');
                charSet.push_back('c');
                break;
            case '3':
                charSet.push_back('d');
                charSet.push_back('e');
                charSet.push_back('f');
                break;
            case '4':
                charSet.push_back('g');
                charSet.push_back('h');
                charSet.push_back('i');
                break;
            case '5':
                charSet.push_back('j');
                charSet.push_back('k');
                charSet.push_back('l');
                break;
            case '6':
                charSet.push_back('m');
                charSet.push_back('n');
                charSet.push_back('o');
                break;
            case '7':
                charSet.push_back('p');
                charSet.push_back('q');
                charSet.push_back('r');
                charSet.push_back('s');
                break;
            case '8':
                charSet.push_back('t');
                charSet.push_back('u');
                charSet.push_back('v');
                break;
            case '9':
                charSet.push_back('w');
                charSet.push_back('x');
                charSet.push_back('y');
                charSet.push_back('z');
                break;
        }
        return charSet;
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits == "") {
            ans.push_back("");
            return ans;
        }
            
        string prev_Digits = "";
        for(int i = 0; i < digits.size() - 1; ++ i)
            prev_Digits += digits[i];
        ans = letterCombinations(prev_Digits);
        int num = ans.size();
        for(int i = 0; i < num; ++ i) {
            vector<char> charSet = getCharSet(digits[digits.size() - 1]);
            string temp;
            for(int j = 0; j < charSet.size(); ++ j) {
                temp = ans[i] + charSet[j];
                ans.push_back(temp);
            }
            ans.pop_back();
            ans[i] = temp;
        }
        return ans;
    }
};