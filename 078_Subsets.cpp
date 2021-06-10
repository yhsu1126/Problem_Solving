class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        result.emplace_back( vector<int>() );
        int size = 1;
        for( auto it = nums.begin(); it != nums.end() ; it++ ){
            for(int i = 0;i<size;i++ ){
                vector<int> tmp(result[i]);
                tmp.emplace_back( *it );
                result.emplace_back( tmp );
            }
            size = size * 2;
        }
        return result;
    }
};

/*
subset problem

for n elementts in array, the amount of subset is 2^n, since for every element we can choose either take it or not

Time Complexity
O(2^n)
Space Complexity
O(2^n) --> O(1) if we don't count the return result
*/