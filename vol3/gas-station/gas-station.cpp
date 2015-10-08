class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();
        if(n == 0)
            return - 1;
        int i = 0, start = 0, end = 0, totalGas = 0;
        for(int j = 0; j < n - 1; ++ j) {
            totalGas += gas[i] - cost[i];
            if(totalGas >= 0) {
                ++ end;
                i = end;
            }
            else {
                start --;
                if(start < 0)
                    start = n - 1;
                i = start;
            }
        }
        
        totalGas += gas[i] - cost[i];
        if(totalGas >= 0)
            return start;
        else
            return -1;
    }
};