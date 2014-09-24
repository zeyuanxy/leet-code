class Solution {
public:
    int minDistance(string word1, string word2) {
            int len_a = word1.length(), len_b = word2.length();
			int *d0 = new int[len_b + 1], *d1 = new int[len_b + 1];
        	for(int i = 0; i <= len_a; ++ i)
        	{
            	for(int j = 0; j <= len_b; ++ j) 
            	{
                	if(i == 0)
                    	d1[j] = j;
                	else if(j == 0)
                    	d1[j] = i;
                	else if(word1[i - 1] == word2[j - 1])
                        d1[j] = d0[j - 1];
                    else
                        d1[j] = 1 + min(min(d0[j - 1], d0[j]), d1[j - 1]);
                }
                swap(d0, d1);
            }
			return d0[len_b];
    }
};