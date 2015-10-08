class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> number;
        for(auto & t : tokens) {
            if(isdigit(t[0]) || t.size() > 1)
                number.push(atoi(t.c_str()));
            else {
                int o1, o2;
                o2 = number.top();
                number.pop();
                o1 = number.top();
                number.pop();
                switch(t[0]) {  
                    case '+':  
                        number.push(o1 + o2);  
                        break;  
                    case '-':  
                        number.push(o1 - o2);  
                        break;  
                    case '*':  
                        number.push(o1 * o2);  
                        break;  
                    case '/':  
                        number.push(o1 / o2);  
                        break;  
                }  
            }
        }
        return number.top();
    }
};