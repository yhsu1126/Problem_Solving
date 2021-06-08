class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if( nums.size() < 3 ){
            return vector<vector<int>>();
        }
        sort( nums.begin(), nums.end());
        int i,head,tail,sum,j;
        vector<vector<int>> answer;
        i=0;
        while( i < nums.size()-2 ){
            sum = 0 - nums[i];
            head = i+1;
            tail = nums.size()-1;
            while( head < tail ){
                if( nums[head] + nums[tail] < sum ){
                    head++;
                }
                else if( nums[head]+ nums[tail] > sum ){
                    tail--;
                }
                else{
                    vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[head]);
                    tmp.push_back(nums[tail]);
                    answer.push_back(tmp);
                    j = head;
                    while( nums[head] == nums[j] && head < tail ){
                        head++;
                    }
                }
            }
            j=i;
            while( nums[i] == nums[j] && i < nums.size()-2 ){
                i++;
            }
        }
        return answer;
    }
};

/*
A common technique for 2sum, 3sum, 4sum...

1. first sort the array
2. start from the smallest and set left and right boundary, if left+right > sum then right -- , else left ++;
3. return all match set

Time Complexity
O(nlogn)

Space Complexity
O(1)
*/
