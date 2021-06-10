class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()<=1 ){
            return intervals;
        }
        std::vector<std::pair< int, int >> intervals_pair;
        for( auto item : intervals  ){
            intervals_pair.push_back( std::make_pair( item[0], item[1] ));
        }
        std:sort( intervals_pair.begin(),intervals_pair.end() );
        int i, left, right;
        vector<vector<int>>result;
        for( i = 0; i < intervals_pair.size()-1;i++ ){
            left = intervals_pair[i].first;
            right = intervals_pair[i].second;
            while(i< intervals_pair.size() - 1 && right >= intervals_pair[i+1].first ){
                right = max( intervals_pair[i+1].second, right );
                i++;
            }
            vector<int> tmp;
            tmp.push_back( left );
            tmp.push_back( right );
            result.push_back(tmp);
        }
        if( i == intervals_pair.size()-1 ){
            vector<int> tmp;
            tmp.push_back( intervals_pair[i].first );
            tmp.push_back( intervals_pair[i].second );
            result.push_back(tmp);
        }
        return result;
    }
};

/*
hard part of this problem is that the intervals does not need to be sorted
meaning you'll got this kind of input
[[1,3], [8,10] , [2,6] ,[15,18]] ( index 1 and 2 is not sorted by first element )

Time Complexity
O( nlogn )
Space Complexity
O(n)
*/