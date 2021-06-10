class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string s : strs) {
            mp[strSort(s)].push_back(s);
        }
        vector<vector<string>> anagrams;
        for (auto p : mp) { 
            anagrams.push_back(p.second);
        }
        return anagrams;
    }
private:
    string strSort(string s) {
        int n = s.size(), counter[26] = {0};
        for (char c : s) {
            counter[c - 'a']++;
        }
        string t;
        for (int c = 0; c < 26; c++) {
            t += string(counter[c], c + 'a');
        }
        return t;
    }
};

/*
Use a map to do this
sort the string alphabetically
use the sorted string as key
then traverse the map to add all the result
Time Complexity
O(n)
Space Complexity
O(n)
*/