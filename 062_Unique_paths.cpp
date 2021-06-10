class Solution {
public:
    int uniquePaths(int m, int n) {
        int sum = m+n-2,i;
        long long int divide,result;;
        if( m < n ){
            swap(m,n);
        }
        result = 1;
        divide = 1;
        for( i = m;i<=sum;i++ ){
            result *= i;
        }
        for( i = 1; i < n ; i++ ){
            divide *= i;
        }
        result /= divide;
        return result;
    }
};
/*
Math problem
O(m) or O(n)
Space Complexity
O(1)
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp_table[m][n],i,j;
        for( i = 0 ; i < m;i++){
            dp_table[i][0] = 1;
        }

        for( i = 0 ; i < n;i++){
            dp_table[0][i] = 1;
        }

        for( i = 1;i<=m-1;i++ ){
            for( j = 1 ; j<=n-1;j++ ){
                dp_table[i][j] = dp_table[i-1][j] + dp_table[i][j-1];
            }
        }
        return dp_table[m-1][n-1];
    }
};

/*
A simple DP to record
this can also use to find the least weight or max weight path
Time Complexity
O( mn )
Space Complexity
O(mn)
*/
