// Problem description:
// 在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
// 请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数


#include <vector>
using namespace std;

// 使用递归recursive的方法求解：
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        bool res = false;
        int row = array.size();
        if (row == 0)
            return res;
        int col = array[0].size();
        return recursive(array, target, row-1, 0);
    }
    
    bool recursive(vector<vector<int>> &array, int &target, int row, int col){
        if(row < 0 or col >= array[0].size())
            return false;
        else if (array[row][col] == target)
            return true;
        else if (array[row][col] < target)
            return recursive(array, target, row, col+1);
        else
            return recursive(array, target, row-1, col);
    }
};


// 如果知道递归的次数，也就是知道了循环的终止条件
// 可以用循环来实现：



