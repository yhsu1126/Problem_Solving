class Solution {
public:
    bool canJump(vector<int>& nums) {
        int index = 0;
        int destin, destin_index, i;
        while( 1 ){
            if( index + nums[index] >= nums.size() - 1 ){
                return true;
            }
            else if ( nums[ index] == 0 ){
                return false;
            }
            
            destin = 0;
            for( i = nums[index]; i > 0 ; i-- ){
                if( destin < index + i + nums[index + i] ){
                    destin_index = i;
                    destin = index+i;
                }
            }
            index += destin_index;
        }
    }
};

/*
Same as jumping game 2
A very nice greedy problem
everytime you decide to jump, you can jump to a range of destination, if the fewest step to the end can only achieved
by jump to certain block, a block that cover most of the destination will sure include such blocks.
Time Complexity O(n)
Space Complexity O(1)

another way to explain this is described in the following url
https://lenchen.medium.com/leetcode-55-jump-game-d95b482642

and the only case where the stuff return false is when we jump to 0
*/