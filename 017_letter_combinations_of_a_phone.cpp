class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() ==0){
            return vector<string>();
        }
        vector<string> mapping;
        mapping.push_back("abc");
        mapping.push_back("def");
        mapping.push_back("ghi");
        mapping.push_back("jkl");
        mapping.push_back("mno");
        mapping.push_back("pqrs");
        mapping.push_back("tuv");
        mapping.push_back("wxyz");
        vector<string> answer;
        int combinations=1,i,j,boundary,index, remain;
        for( i=0;i<digits.size();i++ ){
            if( digits[i]=='7' || digits[i]=='9'){
                combinations *= 4;
            }
            else{
                combinations *= 3;
            }
        }
        for( i=0;i<combinations;i++ ){
            boundary = combinations;
            string tmp;
            for( j = 0 ; j < digits.size(); j++ ){
                index = (int)(digits[j] - '0');
                index -= 2;
                if(digits[j]=='7' || digits[j]=='9'){
                     remain = 4;
                }
                else{
                    remain = 3;
                }
                boundary /= remain;
                tmp.push_back( mapping[index][ (i/boundary)%remain ] );
            }
            answer.push_back(tmp);
        }
        return answer;
    }
};
/*
math problem

Time Complexity
O( 4^n )

Space Complexity
O(1)

*/