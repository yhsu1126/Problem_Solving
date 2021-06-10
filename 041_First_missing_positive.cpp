class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i;
        for( i = 0; i< nums.size();i++ ){
            while( nums[i] > 0 && nums[i] < nums.size() && nums[i] != i+1 ){
                if( nums[ nums[i] - 1 ] == nums[i] ){ //nums[2] = 1 nums[0]=1 , loop occured, break it
                    break;
                }
                std::swap( nums[i], nums[ nums[i] - 1 ] );
            }
        }
        for( i = 0; i< nums.size();i++ ){
            if( nums[i] != i+1  ){
                return i+1;
            }
        }
        return i+1;
    }
};

/*we could try to arrange the array into 
array[i] 1 2 3 4 5 ...
index    0 1 2 3 4 ...
if array[i] = 4 is in range 1 ~ n
then we would swap array[i] with array[ 3 ] and if the new array[i] still fell in the range, we'll swap it again

after this start form 0~ n-1 to find which positive number is missing

Time Complexity
O(n)
Space Complexity
O(1)

*/