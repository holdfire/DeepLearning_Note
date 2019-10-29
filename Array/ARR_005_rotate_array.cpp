//
// Created by LiuXing on 2019/10/29.
//LeetCode # 189 rotate array

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<int> &nums, int k){
        int n = nums.size();
        if (n == 0)
            return;
        k = k % n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
        return;
    }
}