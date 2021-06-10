class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i, last,sum;
        sum = nums[0];
        last = nums[0];
        for( i = 1; i < nums.size();i++ ){
            last = max( nums[i], nums[i] + last);
            sum = max( sum, last );
        }
        return sum;
    }
};

/*
another dynamic programming problem
a table that record at index i , where  the value is the local maximum sum
dp[i] = ( dp[i]-1 + i ) >  i ? dp[i] -1 + i: i;
and since we only this dp[i] can use a variable to store and another variable to store the global max sum
we can reduce the space to O(1)
Time Complexity
O(n)
Space Complexity
O(1)
*/