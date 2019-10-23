//
// Created by LiuXing on 2019/10/23.
// LeetCode #1

#include <vector>
#include <unordered_map>

class solution{
public:
    vector<int> twoSum(vector<int>& nums, int target){
        vector<int> res;
        unordered_map<int, int> hash;
        hash[nums[0]] = 0;
        for(int i = 1; i < nums.size(); i++){
            if(hash.find(target - nums[i]) != hash.end()){
                res.push_back(i);
                res.push_back(hash[target - nums[i]]);
                return res;
            }
            hash[nums[i]] = i;
        }
        return res;
    }

};




