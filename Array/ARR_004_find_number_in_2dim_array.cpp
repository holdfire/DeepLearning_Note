//
// Created by LiuXing on 2019/10/28.
// 剑指offer第4题：查找二维数组中的数字
// 利用矩阵的大小关系，divide and conquer

#include <vector>
using namespace std;

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int rows = array.size();
        if(rows == 0)
            return false;
        int cols = array[0].size();
        int i = 0, j = cols-1;
        while(i < rows && j >= 0){
            if(array[i][j] == target)
                return true;
            else if(array[i][j] < target)
                i++;
            else
                j--;
        }
        return false;
    }
};