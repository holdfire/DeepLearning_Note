#include <vector>
#include <unordered_map>
#include <iostream> 
#include <algorithm>
using namespace std;


// 使用并查集和kruskal算法构造最小生成树
class Djset{
public:
    vector<int> parent;
    vector<int> rank;
    vector<int> size;       // 记录每个连通图包含节点的数目
    vector<int> len;        // 记录每个连通图当前边长的总和；
    int num;

    Djset(int n): parent(vector<int>(n)), rank(vector<int>(n)), size(vector<int>(n, 1)), len(vector<int>(n, 0)), num(n){
        for (int i = 0; i < num; i++)
            parent[i] = i;
    };

    // 路径压缩
    int find(int x){
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    // 合并过程：优化
    void merge(int x, int y){
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty){
            if (rank[rootx] < rank[rooty])
                swap(rootx, rooty);
            parent[rooty] = rootx;
            if (rank[rootx] == rank[rooty])
                rank[rootx] += 1;
        }
    }
};

bool cmp(vector<int>a, vector<int>b){ return a[2] < b[2];};


vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
    sort(edges.begin(), edges.end(), cmp);
    
    unordered_map<vector<int>, int> hash;
    Djset ds(n);

    for (int i = 0; i < n; i++){

    }


}


