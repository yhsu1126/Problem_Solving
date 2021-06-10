class Solution {
public:
    void dfs_search( vector<int>& candidates, vector<int> queue, int minimum ,int target, vector<vector<int>>& result ){
        if( target == 0 ){
            result.push_back( queue );
            return;
        }
        
        for( int i = minimum ; i < candidates.size();i++ ){
            if( candidates[i] > target ){
                return;
            }
            queue.push_back( candidates[i] );
            dfs_search( candidates, queue, i, target - candidates[i], result );
            queue.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::sort( candidates.begin(), candidates.end() );
        vector<vector<int>> result;
        dfs_search( candidates, vector<int>(), 0, target, result);
        return result;
    }
};
/*
dfs search for this problem
if the remain is smaller then current target, return

Time Complexity
O( n^t )
Space Complexity
O( n^t )

*/