class Solution {
public:
    int numTrees(int n) {
        int combination[n+1],i,j;
        memset( combination, 0, sizeof( int )*(n+1) );
        combination[0] = 1;
        combination[1] = 1;
        for( i = 2; i <= n;i++ ){
            
            for( j=0;j<i;j++ ){
                combination[i] += combination[ j ] * combination[ i-j-1 ];
            }
        }
        return combination[n];
    }
};

/*
this is a dp problem

for example if we want to calculate the numTrees of 4 nodes

then the combination should be

     O          O       O       O
 ooo   null    o oo   oo o  null  ooo

to calculat the combination of child, we need to calculate numTree(3) numTree(2) numTree(1) and numTree(0)
then we could get 
numTrees(4) = numTress(3)*numTrees(0) + numTress(2)*numTrees(1) + numTress(1)*numTrees(2) + numTress(0)*numTrees(3)
numTrees(0) = 1, numTrees(1) = 1

Time Complexity
O(n^2) --> 2+3+4+...+n
Space Complexity
O(n)
*/