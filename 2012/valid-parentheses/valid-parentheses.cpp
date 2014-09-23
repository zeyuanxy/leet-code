class Solution {
public:
    int getValue(char c) {
        switch(c) {
            case '(' : return 1;
            case ')' : return -1;
            case '[' : return 2;
            case ']' : return -2;
            case '{' : return 3;
            case '}' : return -3;
            default:
                return 0;
        }
    }
    
    bool isValid(string s) {
        vector<char> stack;
        for(int i = 0; i < s.length(); ++ i)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                stack.push_back(s[i]);
            else
            {
                char c = ' ';
                if(stack.size() > 0)
                {
                    c = stack[stack.size() - 1];
                    stack.pop_back();
                }
                if(getValue(c) != -getValue(s[i]))
                    return false;
            }
        }
        if(stack.size() == 0)
            return true;
        else
            return false;
    }
};