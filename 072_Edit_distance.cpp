class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        int dp_table[len1+1][len2+1];
        int i,j;
        for( i=0;i<=len1;i++ ){
            for( j=0;j<=len2;j++){
                if( i==0 ){
                    dp_table[i][j] = j;
                }
                else if ( j ==0 ){
                    dp_table[i][j] = i;
                }
                else{
                    if( word1[i-1] == word2[j-1] ){
                        dp_table[i][j] = dp_table[i-1][j-1];
                    }
                    else{
                        dp_table[i][j] = 1 + min(min( dp_table[i-1][j], dp_table[i][j-1]), dp_table[i-1][j-1]);
                    }
                }
            }
        }
        return dp_table[len1][len2];
    }
};

/*
depends how you define the dp table

if row is word1, row2 is word2
word1 = horse
word2 = ros
then for this equation
dp_table[i][j] = 1 + min(min( dp_table[i-1][j], dp_table[i][j-1]), dp_table[i-1][j-1]);

dp_table[i-1][j]
means something like we know the number of ways to change "hors" to "ros"
now we want to change "horse" to "ros"
then for every method we add another step at first "horse" remove "e"

dp_table[i][j-1]
means something like we know the number of ways to change "horse" to "ro"
now we want to change "horse" to "ros"
then for every method we add another step at last "ro" add "s"

dp_table[i-1][j-1]
means something like we change "hors" to "ro"
now we want to change "horse" to "ros"
meaning we could first change "hors 'e'" to "ro 'e'" because we know how to change "hors" to "ro" then replace 'e' with 's'

however 
if we if we want to know the dp value of "ho" to "ro" since the 'o' is same, the number is the same as dp[i-1][j-1];

Time Complexity
O( l1 * l2 )
Space Complexity
O( l1 * l2 )
*/