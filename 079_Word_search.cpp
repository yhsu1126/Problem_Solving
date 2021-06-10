class Solution {
public:
    int dirX[4]={ 1,-1,0,0 };
    int dirY[4]={ 0,0,1,-1 };
    bool checkBoundary( int row, int col, int x, int y ){
        return ( x >=0 && x < row ) && ( y >=0 && y < col );
    }
    bool dfsSearch( string word, vector<vector<char>>& board, int i, int j, int index ){
        if( board[i][j] == word[index] ){
            board[i][j]='*';
            if(index == word.size()-1){
                return true;
            }
        }
        else{
            return false;
        }
        int k;
        for( k=0;k<4;k++){
            if( checkBoundary( board.size(), board[0].size(), i+dirX[k], j+dirY[k] ) ){
               if(dfsSearch( word, board, i+dirX[k], j+dirY[k], index+1 )){
                   return true;
               }
            }
        }
        board[i][j] = word[index];
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int i,j;
        for(i=0;i<board.size();i++){
            for( j=0;j<board[0].size();j++ ){
                if( board[i][j] == word[0] ){
                    if(dfsSearch( word, board, i,j,0 )){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

/*

DFS Search problem
Time Complexity
O( m * n * 4^s )
Space Complexity
O( 4^s )
*/