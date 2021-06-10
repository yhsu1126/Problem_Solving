class Solution {
public:
    int calculateRectangle( vector<int> heights ){
        std::stack<int> leftIndex;
        int i, maxArea=0, h, left, result;
        for( i=0;i<heights.size();i++ ){
            while( !leftIndex.empty() && heights[leftIndex.top()] >= heights[i] ){
                h = heights[ leftIndex.top() ];
                leftIndex.pop();
                left = leftIndex.empty()? -1 : leftIndex.top();
                result = h * ( i - left -1 );
                maxArea = std::max( maxArea, result );
            }
            leftIndex.push( i );
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        std::vector<int> heights;
        int maxArea=0,i,j,length;
        if( matrix.size()==0 ){
            return 0;
        }
        length = matrix[0].size();
        for( i=0;i<length;i++ ){
            if( matrix[0][i]=='0' ){
                heights.push_back( 0 );
            }
            else{
                heights.push_back( 1 );
            }
        }
        heights.push_back(0);
        maxArea = std::max( maxArea, calculateRectangle( heights ) );
        for( i=1;i<matrix.size();i++ ){
            for( j=0;j<length;j++ ){
                if( matrix[i][j]=='1' ){
                    heights[j]++;
                }
                else{
                    heights[j]=0;
                }
            }
            maxArea = std::max( maxArea, calculateRectangle( heights ) );
        }
        return maxArea;
    }
};

/*
we need the solution to find largest rectangle in histogram.
now for every row inside 2d matrix we construct the histogram by the following method

every time we scan the row if the value is not null, add 1 to the height at this index
else, the height at this index is 0;

then we find the maximum rectangle in this histogram

record a global maximum for every histogram
return this maximum

Time Complexity
O( row * col ) --> O( col ) for constructing histogram and find maximum rectangle, O( row ) time to traverse the 2d matrix

Space Complexity
O(Col) --> only need a stack to calculate rectangle

*/