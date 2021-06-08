class Solution {
public:
    int maxArea(vector<int>& height) {
        int head,tail,max,tmp;
        head = 0;
        tail = height.size()-1;
        max = 0;
        while( tail > head ){
           tmp = min(height[tail],height[head])*(tail-head);
           max = tmp > max ? tmp : max;
           if( height[tail] > height[ head ] ){
               head++;
           }
            else{
                tail--;
            }
        }
        return max;
    }
};
/*

Intuitively, the widest container can hold the most water

if we want to reduce the width, we need to make sure the height is actually higher to be able to hold more water

So start from both edge, we'll move the smaller one and recalculate the size again, record the max one and return it

Time Complexity
O(n)
Space Complexity
O(1)

*/