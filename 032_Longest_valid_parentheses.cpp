class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> dp(s.size(),0);
        int result=0;
        for( int i=1;i<s.size();i++ ){
            if(s[i] ==')' && i-dp[i-1]-1>=0 && s[i-dp[i-1]-1]=='(' ){
                dp[i] = 2 + dp[i-1];
                if( i - dp[i-1] -2 >=0 ){
                    dp[i] += dp[i - dp[i-1] -2 ];
                }
                result = std::max( result,dp[i] );
            }
        }
        return result;
    }
};

/*
use a dp table to record the length of valid parentheses are in this region

dp table will record the length of the parentheses, so if we saw a ')' at index "i" then we check length of dp[i-1],
then we check if String S[i-dp[i-1]-1] == '(' if true, the value is 2 + dp[i-1], then consider such case
 S ( ) ( ( ) )
dp 0 2 0 0 2 ? <--the value here will be 4 if we only use the above logic, we should add dp[ i - dp[i-1] -2 ]
   0 1 2 3 4 5
   
return the max value in dp table then we got the answer

Time Complexity
O(n)
Space Complexity
O(n)
*/