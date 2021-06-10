struct listNode{
    char c;
    int index;
    struct listNode* next;
    listNode( char, int );
};

listNode::listNode( char _c, int _index ){
    this->c = _c;
    this->index =_index;
    this->next = nullptr;
}

typedef std::unordered_map<char,int> charMap;

class Solution {
public:
    string minWindow(string s, string t) {
        charMap targetMap;
        int i,minLength,minl, minr,count;
        struct listNode *filtered, *index, *left, *right;
        count=0;
        for( auto it = t.begin() ; it != t.end();it++ ){
            auto got = targetMap.find( *it );
            if( got  == targetMap.end() ){
                targetMap.insert( std::make_pair( *it , 1 ) );
                count ++;
            }
            else{
                got->second += 1;
            }
        }
        filtered = nullptr;
        i=0;
        for( auto it = s.begin(); it != s.end(); it++ ){
            auto got = targetMap.find( *it );
            if( got != targetMap.end() ){
                if( filtered == nullptr ){
                    filtered = new listNode( *it, i );
                    index = filtered;
                }
                else{
                    struct listNode *tmp = new listNode( *it, i );
                    index->next = tmp;
                    index = index->next;
                }
            }
            i++;
        }
        index = filtered;
        left = index;
        right = index;
        minLength = s.size()+1;
        minl = -1;
        minr = -1;
        while( right != nullptr ){
            auto got = targetMap.find( right->c );
            got->second -=1;
            if( got->second==0 ){
                count--;
                while( count ==0 ){
                    int length = right->index - left->index + 1;
                    if( minLength > length ){
                        minLength = length;
                        minl = left->index;
                        minr = right->index;
                    }
                    auto got2 = targetMap.find( left->c );
                    got2->second +=1;
                    if( got2->second >0 ){
                        count++;
                    }
                    left=left->next;
                }
            }
            right = right->next;;
        }
        if( minl !=-1 ){
            std::string result( s.begin()+minl, s.begin()+minr+1 );
            return result;
        }
        else{
            return string();
        }
    }
};


/*
we use leetcode solution to solve this
use a map to record the characters inside the target string
Example: 'A' exists 2 times inside target string "BAAC"

then we loop throught the test string and filter out only the character with the target string, and record the index
of these characters
Example : for target string "BAAC" we only record the index of character 'B', 'A' and 'C'

loop throught the filtered list, if we have all the characters, count the length, compare with min length
return the global minimum

Time Complexity
O( S+T )
Space Complexity
O(S+T)

*/