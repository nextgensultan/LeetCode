class Solution {
public:
    int numSplits(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(26,0));
        dp[0][s[0] - 'a'] = 1;
        for(int i=1;i<s.size();i++)
            for(int j=0;j<26;j++)
                dp[i][j] = dp[i-1][j] + int((j+'a') == s[i]);
        int result =0;
        for(int i=0;i<s.size()-1;i++)
        {
            int c1=0,c2=0;
            for(int j=0;j<26;j++)
            {
                if(dp[i][j])
                    c1++;
                if(dp[s.size()-1][j]!= dp[i][j])
                    c2++;
            }
            result+= (c1==c2);
        }
        return result;
    }
};