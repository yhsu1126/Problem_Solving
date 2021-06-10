inline void myswap( int *a, int *b ){
    if( a==b ){
        return;
    }
    int tmp = *a^*b;
    *a =  tmp ^ *a;
    *b = tmp ^ *a;
}

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int r=0;  //red 0 should be left
        int w=0;  // white 1 should be middle
        int b=nums.size()-1;  // blue 2 should be right
        int i;
        while( b >= w ){
            if( nums[w] ==0 ){
                //myswap( &(nums[w]), &( nums[r] ) );
                std::swap( nums[w], nums[r] );
                w++;
                r++;
            }
            else if ( nums[w] == 1 ){
                w++;
            }
            else{
                //myswap( &(nums[b]),&(nums[w]) );
                std::swap( nums[b], nums[w] );
                b--;
            }
        }
    }
};

/*
since need to swap in place, we should have a left border meaning where the next red should be
and a right border meaning where the next blue should be
and an index of white meaning where the next white should be

Time complexity
O(n)
Space Complexity
O(1)
*/