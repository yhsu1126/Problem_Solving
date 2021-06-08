class Solution {
public:
    bool isMatch(string s, string p) {
        s.insert( s.begin(), '.' );
        p.insert( p.begin(), '.' );
        int dp_table[p.size()][s.size()];
        memset(dp_table, 0,sizeof(int)*p.size()*s.size());
        int i,j;
        dp_table[0][0] = 1;
        for( i=1; i<p.size();i++){
            if(p[i]=='*'){
                dp_table[i][0]=dp_table[i-2][0];
            }
        }
        for(i=1;i<p.size();i++){
            for( j=1;j<s.size();j++){
                if( p[i]=='.' ){
                    dp_table[i][j]=dp_table[i-1][j-1];
                }
                else if( p[i]=='*' ){
                    if( p[i-1] == '.'){
                        dp_table[i][j] = dp_table[i-2][j] | dp_table[i-1][j] | dp_table[i][j-1];
                    }
                    else{
                        dp_table[i][j] = dp_table[i-2][j] | dp_table[i-1][j];
                        if( p[i-1] == s[j] && p[ i -1 ]==s[ j-1 ] ){
                            dp_table[i][j] |= dp_table[i][j-1];
                        }
                    }
                }
                else{
                    if( p[i] == s[j] ){
                        dp_table[i][j]=dp_table[i-1][j-1];
                    }
                }
            }
        }
        if( dp_table[p.size()-1][s.size()-1] == 1 ){
            return true;
        }
        else{
            return false;
        }
    }
};

/*
Classic DP problem

Time Complexity
O( SP )
Space Complexity
O( SP )

the only tricky part is the '*' symbol
take s = 'mississippi' and p = 'mis*is*p*.' as example

  . m i s s i s s i p p i
. 1 0 0 0 0 0 0 0 0 0 0 0
m 0 ...
i 0 .
s 0 .
* 0
i 0
s 0
* 0
p 0
* 0                     0 <--it this is 0 then false, else true

first of all '*' need initial setup
for s = 'abcde' and p = '.*'

  . a b c d e
. 1 0 0 0 0 0
. 0 1 0 0 0 0
* 1 <-- this 1 should be inherited from [position of *] - 2

for * you should also check for

  a b
a 1 0
* ? <-- check for the one above and the one above it for 2 condition, whether it's null or appeared once

if the character before * match current position of s and the previous value match, then we could check 
  .  a a a a a
. 1  0 0 0 0 0
a 0  1 0 0 0 0
* 1 [1] ? <-- so we should check position of []

*/