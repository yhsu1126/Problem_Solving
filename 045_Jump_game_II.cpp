class Solution {
public:
    int jump(vector<int>& nums) {
        int step=0,index=0,i,max,max_index;
        if(nums.size()==1 ){
            return step;
        }
        while( 1 ){
            if( index + nums[index] >= nums.size()-1 ){
                return step+1;
            }
            max=0;
            for(i = 1; i <= nums[index];i++){
                if( max<=nums[index+i] + i ){
                    max = nums[index+i] + i;
                    max_index = i;
                }
            }
            index += max_index;
            step+=1;
        }
    }
};
/*
A very nice greedy problem
everytime you decide to jump, you can jump to a range of destination, if the fewest step to the end can only achieved
by jump to certain block, a block that cover most of the destination will sure include such blocks.
Time Complexity O(n)
Space Complexity O(1)

another way to explain this is described in the following url
https://lenchen.medium.com/leetcode-55-jump-game-d95b482642

*/