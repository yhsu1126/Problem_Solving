class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int i, h, l, result;
        std::stack<int> leftIndex;
        result=0;
        for( int i=0;i < heights.size();i++ ){
            while( (!leftIndex.empty()) && ( heights[ leftIndex.top() ] >= heights[i] ) ){
                h = heights[ leftIndex.top() ];
                leftIndex.pop();
                l = leftIndex.empty()? -1 : leftIndex.top();
                result = std::max( result, h * ( i-l-1 ) );
            }
            leftIndex.push(i);
        }
        return result;
    }
};

/*
To get the maximum rectangle, we could make sure the current index is the right boundary,
try to extend to the left as much as possible
this is a  next greater element problem

1.we could push the index of the height into a stack
2.when a new height is found, if the height is higher then the top of stack, we could safely push it into the stack,
because we cannot extend this height left to form a rectangle
3. if the new height is smaller, we 'll pop from the stack and calculate the pop height's local max rectangle
until we found another height at top that is smaller than the current new height

Time Complexity
O(n) --> since every height will be push and pop once
Space Complexity
O(n) 
*/