class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left, right, head, tail,index;
        head = 0;
        right=-1;
        left = -1;
        tail = nums.size()-1;
        vector<int> result(2,-1);
        if(nums.size()==0){
            return result;
        }
        if(nums.back() == target ){
            right = nums.size()-1;
        }
        else{
            head = 0;
            tail = nums.size()-1;
            while(1){
                index = ( head + tail )/2;
                if( nums[index] <= target ){
                    head = index+1;
                }
                else{
                    if( index>0 && nums[index-1] ==target ){
                        right = index-1;
                        break;
                    }
                    else{
                        tail = index-1;
                    }
                }
                if( head > tail ){
                    return result;
                }
            }
        }
        if(nums.front() == target ){
            left = 0;
        }
        else{
            head = 0;
            tail = nums.size()-1;
            while(1){
                index = ( head + tail )/2;
                if( nums[index] >= target ){
                    tail = index-1;
                }
                else{
                    if( index<nums.size() && nums[index+1] == target ){
                        left = index+1;
                        break;
                    }
                    else{
                        head = index+1;
                    }
                }
            }
        }
        result[0] = left;
        result[1] = right;
        return result;
    }
};

/*

perform two binary search

Time Complexity
O(logn)
Space Complexity
O(logn)

*/