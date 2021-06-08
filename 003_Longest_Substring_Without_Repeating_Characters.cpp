class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        uint8_t count[256]={ 0 };
        uint8_t tmp;
        int maxLength = 0,curLength = 0;
        auto head = s.begin();
        auto tail = s.begin();
        while( tail != s.end() ){
            tmp = (uint8_t)(*tail);
            count[tmp]++;
            curLength++;
            while( count[tmp] > 1 ){
                count[(uint8_t)(*head)]--;
                curLength--;
                head++;
            }
            maxLength = (maxLength < curLength)?curLength:maxLength;
            tail++;
        }
        return maxLength;
    }
};
/*
Since only 256 kinds of character exist, just use a hashmap to check how many word is inside the subwindow

Time Complexity O(n)

Space Complexity O(1) ( map size is 256, constant )
*/