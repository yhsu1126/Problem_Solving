class Solution {
public:
    void dpsGenerateParenthesis( int maxParenthesis, int validParenthesis, string s, vector<string>& allResult ){
        if(maxParenthesis == validParenthesis){
            int i,remainLength = 2*maxParenthesis - s.size();
            for( i = 0; i < remainLength;i++ ){
                s.push_back(')');
            }
            allResult.push_back( s );
            return;
        }
        dpsGenerateParenthesis( maxParenthesis, validParenthesis+1, s+'(', allResult );
        if( 2 * validParenthesis > s.size() ){
            dpsGenerateParenthesis( maxParenthesis, validParenthesis, s+')', allResult );
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> allResult;
        dpsGenerateParenthesis( n, 1, "(", allResult );
        return allResult;
    }
};

/*

worst dps method is without any pruning

we basically add two pruning, if we have enough '(', fill the rest of the string with ')'

if current length contains enough ' ) ', we don't need to traverse the tree

Time Complexity
O( 2^n * n )
Space Complexity
O( 2^n * n ) // we calculate stack size as well

*/