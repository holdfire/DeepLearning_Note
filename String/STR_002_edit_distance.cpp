// 问题来源：https://zhuanlan.zhihu.com/p/80682302
// Created by LiuXing on 2019/11/3.
// LeetCode # 72

/* 问题描述：求编辑距离
 * 给定两个字符串s1和s2，计算出将s1转换成s2所使用的最少操作数
 * 可以对一个字符串就行三种操作：插入一个字符，删除一个字符，替换一个字符
 * 示例：s1 = "horse", s2 = "ros"
 * STEP1: 将'h'替换为'r'
 * STEP2：删除'r'
 * STEP3：删除'e'
*/
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

// 解题思路1：递归与回溯，时间复杂度为指数级
class Solution{
public:
    int editiongDistance(string s1, string s2){
        int m = s1.size();
        int n = s2.size();
        return backtracking(s1, s2, m-1, n-1);
    }

private:
    int backtracking(string &s1, string &s2, int m, int n){
        if (m == -1)
            return n+1;
        if (n == -1)
            return m+1;
        if (s1[m] == s2[n])
            return backtracking(s1, s2, m-1, n-1);
        return min(backtracking(s1,s2,m,n-1)+1,
                backtracking(s1,s2,m-1,n)+1,
                backtracking(s1,s2,m-1,n-1)+1);
    }
};


// 解题思路2：动态规划
class Solution2{
public:
    int editingDistance(string s1, string s2){
        int m = s1.size();
        int n = s2.size();
        int i = 0, j = 0;
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i = 1; i <= m; i++)
            dp[i][0] = i;
        for(int j = 1; j <= n;j++)
            dp[0][j] = j;
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
                if (s1[i-1] == s2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j]= min(
                    dp[i-1][j-1]+1,
                    dp[i-1][j]+1,
                    dp[i][j-1]+1
                    );
        return dp[m][n];
    }
private:
    int min(int a, int b, int c){
        return min(a, min(b,c));
    }
};
