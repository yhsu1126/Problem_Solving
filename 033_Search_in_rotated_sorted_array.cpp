class Solution {
public:
    int rotateConvert(int index, int start, int size ){
        index = index + start;
        if( index >= size ){
            return index - size;
        }
        return index;
    }
    int search(vector<int>& nums, int target) {
        int start=0,head,tail,result = -1;
        if( nums.front() > nums.back() ){
            //binary search the start by comparing the element with the last element
            //4 5 6 7 0 1 2 , compare with 2 to determine if we want to move left or right
            head = 0;
            tail =  nums.size()-1;
            while(1){
                start = (head + tail)/2;
                if( start>0 ){
                    if( nums[start]< nums[ start-1 ] ){
                        break;
                    }
                }
                if( nums[start] < nums.back() ){
                    tail = start -1;
                }
                else{
                    head = start + 1;
                }
            }
        }
        head = 0;
        tail =  nums.size()-1;
        while(1){
            int tmpI = rotateConvert( ( head + tail )/2,start, nums.size() );
            if( nums[tmpI] > target ){
                tail = (head + tail)/2-1;
            }
            else if( nums[tmpI] < target ){
                head = (head + tail)/2+1;
            }
            else{
                result = tmpI;
                break;
            }
            if( head > tail ){
                break;
            }
        }
        return result;
    }
};


/*
perform two binary search to find the value
first time we find the start of the array
second time we find the value

Time Complexity
O(logn)
Space Complexity
O(1)
*/