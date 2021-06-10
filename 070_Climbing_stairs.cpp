class Solution {
public:
    int climbStairs(int n) {
        if( n==1 ){
            return 1;
        }
        else if( n==2 ){
            return 2;
        }
        int dp_table[n],i;
        dp_table[0] = 1;
        dp_table[1] = 2;
        for(i=2;i<n;i++ ){
            dp_table[i] = dp_table[i-1] + dp_table[i-2];
        }
        return dp_table[n-1];
    }
};

/*
dp problem
since we can the way we can climb is from two step or 1 step, we just add both for the result
Time Complexity
O(n)
Space Complexity
O(n)
*/