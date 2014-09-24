class Solution {
public:
    int candy(vector<int> &ratings) {
        if(ratings.empty())
            return 0;
        
        int ret = 1, prevCandy = 1, curCandy = 0;
        int decLength = 0, beforeDec = 1;
        for(int i = 1; i < ratings.size(); ++ i) {
            if(ratings[i] < ratings[i - 1]) {
                ++ decLength;
                if(beforeDec <= decLength)
                    ++ ret;
                ret += decLength;
                prevCandy = 1;
            } else {
                curCandy = (ratings[i] > ratings[i - 1]) ? prevCandy + 1 : 1;
                ret += curCandy;
                prevCandy = curCandy;
                decLength = 0;
                beforeDec = curCandy;
            }
        }
        return ret;
    }
};