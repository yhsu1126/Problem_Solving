class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> result;
        for(int i = 0; i < nums.size(); i++) {
            if(map.find(target - nums[i]) != map.end()){
                result.push_back(i);
                result.push_back(map[target - nums[i]]);
                break;
            }
            map.insert( std::make_pair( nums[i],i) );
        }
        
        return result;
    }
};
/*
Use a hashmap to record all the numbers, return answer if map has another half

Time Complexity O(n)

Space Complexity O(n)

*/