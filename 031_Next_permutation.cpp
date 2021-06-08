class Solution {
public:
    void reverseNums( int l, int r, vector<int>& nums ){
        while( l < r ){
            std::swap( nums[l], nums[r] );
            l++;
            r--;
        }
    }
    int nextGreaterEle( int r, int l, int key, vector<int>& nums ){
        int middle = (l+r)/2;
        while( l < r ){
            if( nums[middle] <= key ){
                if( nums[ middle-1 ] > key ){
                    return middle-1;
                }
                r = middle - 1;
                
            }
            else{
                if( nums[middle+1]<=key ){
                    return middle;
                }
                l=middle+1;
            }
            middle = (l+r)/2;
        }
        return middle;
    }
    void nextPermutation(vector<int>& nums){
        if( nums.size()==1 ){
            return;
        }
        int i=nums.size()-2;
        int len = nums.size();
        int j;
        while( i >= 0 && nums[i+1] <= nums[i] ){
            i--;
        }
        if( i==-1 ){
            reverseNums( 0,  len-1, nums);
            return;
        }
        j = nextGreaterEle( len-1, i+1, nums[i],nums );
        std::swap( nums[j], nums[i] );
        reverseNums( i+1, len-1, nums );
    }
};

/*
Time Complexity
O(n)
Space Complexity
O(1)

to find next permutation
we need to
1. from tail to head find the first number that is smaller than its next one, 15432 the number we need to find is '1'
2. we have the value 1, then we need to find the number that is greater then 1 but smallest inside the remain string
for 15432, the number is '2' ( use binary search to search this part, since the string is descending order )
3. swap the value with the first value then sort the remain string with ascending order, for 15432, we need to swap '1' and '2'
then sort the part '5431' which is 21345 the next permutation of 15432 ( since the original string is descending order
and we swap the smallest value out, just reverse the string)

*/