class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int i,j,k;
        for( i = 0; i < matrix.size();i++ ){
            for( j = i;j<matrix.size();j++ ){
                std::swap( matrix[i][j],matrix[j][i] );
            }
        }
        for( i = 0;i < matrix.size();i++ ){
            j = 0;
            k = matrix.size()-1;
            while( j < k ){
                std::swap( matrix[i][j], matrix[i][k] );
                j++;
                k--;
            }
        }
    }
};
/*
Rotate the image
this can be done by doing a reverse on diagnal and reverse from left to right
for 3d rubix cube , you can use xor swap to swap the border line column without allocating any space
Time Complexity
O(n^2)
Space Complexity
O(1)
*/