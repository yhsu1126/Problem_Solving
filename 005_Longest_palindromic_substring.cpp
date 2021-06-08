class Solution {
public:
    void findZ( char* testString, int* zValue, int i, int* middle, int* right, int j, int curValue, int length ){
        while(1){
            if( (j < length) && (i*2 >= j) ){
                if( testString[j] == testString[ i*2-j ] ){
                    *middle = i;
                    *right = j;
                    curValue += 1;
                    j+=1;
                }
                else{
                    break;
                }
            }
            else{
                break;
            }
        }
        zValue[i] = curValue;
    }
    string longestPalindrome(string s) {
        if( s.size()==1 ){
            return s;
        }
        char testString[2*s.size()+2];
        int length=2*s.size()+2;
        int zValue[length];
        memset( testString, char(0), sizeof(char)*(length) );
        memset( zValue, 0, sizeof(int)*(length) );
        length--;
        int i, middle, right,maxValue=0;
        for( i=0;i < s.size() ; i++ ){
            testString[ i*2 ]='.';
            testString[ i*2 + 1 ]= s[i];
        }
        testString[ i*2 ]='.';
        zValue[0]=0;
        middle = 0;
        right = middle+zValue[middle] - 1;
        for( i=1; i<length;i++ ){ //fill the z value of the new string
            if( i < right ){
                if( i + zValue[ middle * 2 - i ] <right ){
                    zValue[i] = zValue[ middle * 2 - i ];
                    continue;
                }
                else{
                    findZ( testString, zValue, i, &middle, &right, right+1, right-i, length);
                }
            }
            else{
                findZ( testString, zValue, i, &middle, &right, i+1, 0, length);
            }
        }
        //debug( testString, zValue, length );
        for(i=0;i<length;i++){
            if(maxValue < zValue[i]){
                maxValue = zValue[i];
                middle=i;
            }
        }
        string result;
        for( i = middle-maxValue ; i <= middle+maxValue ; i++ ){
            if( testString[i] != '.'){
                result += testString[i];
            }
        }
        return result;
    }
};


/*
A similar version of Z algorithm, where Z value is the length of the palindrom
since palindrom may have null middle character, we can modify our character by adding a special character between

Example : "apple" --> ".a.p.p.l.e."
Example : "a"     --> ".a."

Like zValue, we need to maintain somekind of boundary, if the range of our current candidate is less than the boundary,
we can reuse the value.

http://web.ntnu.edu.tw/~algo/Palindrome.html#3

Time Complexity O(n) --> run 2n length to calculate Z value and find the max of it

Space Complexity O(n)

*/