class Solution {
public:
    void dfs_search( vector<int> nums, vector<int>queue,  vector<vector<int>>& answer ){
        if(nums.size()==1){
            queue.push_back( nums.front() );
            answer.push_back(queue);
        }
        int i,num;
        for(i=0;i<nums.size();i++){
            num = nums[i];
            nums[i] = nums.back();
            nums.pop_back();
            queue.push_back( num );
            dfs_search( nums, queue, answer  );
            queue.pop_back();
            nums.push_back( num );
            std::iter_swap( nums.begin()+i, nums.rbegin() );
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> answer;
        dfs_search( nums, vector<int>(),answer );
        return answer;
    }
};

/*
this dfs acts like the way we do permutation
if the input is [ 1,2,3 ]
first time we'll loop for 1 ,2 and 3
then we remove the number from the queue, which call the function again with the size of array is two
we do thie repeatedly until we have only one choice

Time Complexity
O( n^2 ) --> n+ n-1 +n-2+....+1
Space Complexity
O( n^2 ) --> n+ n-1 +n-2+....+1 ( consider stack size )
*/