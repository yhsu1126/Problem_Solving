class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size()-1, lmax=0, rmax=0, water = 0;
        while( left < right ){
            if( height[left] < height[right] ){
                if( lmax < height[left] ){
                    lmax = height[left];
                }
                else{
                    water += (lmax - height[ left ] );
                }
                left++;
            }
            else{
                if( rmax < height[right] ){
                    rmax = height[right];
                }
                else{
                    water += (rmax - height[ right ] );
                }
                right--;
            }
        }
        return water;
    }
};

/*
leetcode has a very good solution about this

first version is O(n) in Time complexity and Space Complexity

the concept is as follow , maintain two dp table, one table record from left to right the max height encountered at this index
another table recorded the opposite direction, meaning from right to left

When calculating the amount of trapped water, we could use   min( dpL[i], dpR[i] ) - current index height
to know the amount of rain water trapped at this index
-----------------------------------------------------------------------------
However, this solution can enhance into a better solution, since we only need min( dpL[i] , dpR[i] ) to know how much rain water
we can trap, we could use two border, on at left and right, we only move the minimum one
if border move through a index we compare the height
if larger, update the height
else we believe it can trap water and add the amount of water trapped
-----------------------------------------------------------------------------------------
Time Complexity O(n)
Space Complexity O( 1 )

*/