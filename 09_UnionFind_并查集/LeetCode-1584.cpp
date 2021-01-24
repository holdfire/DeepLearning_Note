// Reference: https://leetcode-cn.com/problems/min-cost-to-connect-all-points/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// 方法1：Kruskal算法 + 并查集；（以边为基础，每次从边集合中寻找最小的边）
// 方法2：prim算法得到最小生成树；（以顶点为基础，每次寻找离新树最近的顶点）

class Djset{
public:
    vector<int> parent;
    vector<int> rank;
    vector<int> size;        // 记录每个连通图的节点个数
    vector<int> len;         // 记录每个连通图的所有边的长度
    int num;                 // 节点的个数

    Djset(int n): parent(vector<int>(n)),rank(vector<int>(n)),size(vector<int>(n, 1)),len(vector<int>(n, 0)), num(n){
        for (int i = 0; i < num; i++)
            parent[i] = i;
    }

    int find(int x){
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    // 把计算连通图点数、总边长、判断是否包含全部点数，放在了merge函数里
    int merge(int x, int y, int length){
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty){
            if (rootx < rooty)
                swap(rootx, rooty);
            parent[rooty] = rootx;
            if (rank[rootx] == rank[rooty])
                rank[rootx] += 1;
            
            // 将rooty的节点数目、边长总和累加到rootx上
            size[rootx] += size[rooty];
            len[rootx] += (len[rooty] + length);
            // 如果当前连通分量包含了所有节点，返回结果
            if (size[rootx] == num)
                return len[rootx];
        }
        return -1;
    }
};


struct Edge{
    int start;
    int end;
    int len;
};


int minCostConnectPoints(vector<vector<int>>& points){
    int res = 0;
    int n = points.size();
    Djset ds(n);

    // 把所有的边长存储
    vector<Edge> edges;
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            int len = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
            Edge edge = {i, j, len};
            edges.push_back(edge);
        }
    }

    // 然后依据边长进行排序
    sort(edges.begin(), edges.end(), [](const auto& a, const auto& b){return a.len < b.len;});

    // 然后使用Kruskal算法
    for (auto& e : edges){
        res = ds.merge(e.start, e.end, e.len);
        if (res != -1)
            return res;
    }
    
    return 0;
}