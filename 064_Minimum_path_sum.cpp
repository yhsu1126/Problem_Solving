class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid.front().size();
        int i,j;
        int matrix[row][col], dp_table[row][col];
        auto it = grid.begin();
        auto it2= grid.front().begin();
        for(i=0 ; it != grid.end(); it++,i++  ){
            for( j=0, it2=it->begin(); it2 != it->end() ; it2++,j++){
                matrix[i][j] = *it2;
            }
        }
        dp_table[0][0] = matrix[0][0];
        for( i=1; i<row;i++ ){
            dp_table[i][0] = dp_table[i-1][0] + matrix[i][0];
        }
        for( i = 1;i<col;i++ ){
            dp_table[0][i] = dp_table[0][i-1] + matrix[0][i];
        }
        for( i=1; i<row;i++ ){
            for( j=1;j<col;j++ ){
                dp_table[i][j]= min( dp_table[i-1][j], dp_table[i][j-1] ) + matrix[i][j];
            }
        }
        return dp_table[row-1][col-1];
    }
};

/*
Traditional dp problem, all hard problem are some reduction of this one

Time Complexity
O(mn)
Space Complexity
O(mn)
*/