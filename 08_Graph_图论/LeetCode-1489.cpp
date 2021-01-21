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
    vector<int> len;        // 记录每个连通图当前边长的总和
    int maxlen;             // 连通图中最长的边
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
    int merge(int x, int y, int length){
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty){
            if (rank[rootx] < rank[rooty])
                swap(rootx, rooty);
            parent[rooty] = rootx;
            if (rank[rootx] == rank[rooty])
                rank[rootx] += 1;
            size[rootx] += size[rooty];
            len[rootx] += (len[rooty] + length);
            if (size[rootx] == num){
                maxlen = length;
                return len[rootx];
            }    
        }
        return -1;
    }
};

struct VE{
    int index;    // 在原vector中的索引
    int start;
    int end;
    int len;
};




vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
    vector<vector<int>> res(2);

    // 给所有的边排序
    vector<VE> ves;
    int num_e = edges.size();
    for (int i = 0; i < num_e; i++){
        VE ve = {i, edges[i][0], edges[i][1], edges[i][2]};
        ves.emplace_back(ve);
    }
    sort(ves.begin(), ves.end(), [](const auto& a, const auto& b){ return a.len < b.len;});

    // 生成最小生成树
    Djset ds(n);
    int mstLen = 0;
    for (int i = 0; i < num_e; i++){
        int x = edges[i][0];
        int y = edges[i][1];
        int length = edges[i][2];
        int t = ds.merge(x, y, length);
        if (t != -1){
            mstLen = t;
            break;
        }
    }

    // 比ds.maxlen大的边一定不在最小生成树中；
    vector<bool> inMST(num_e, true);
    for (int i = 0; i < num_e; i++)
        if (ves[i].len > ds.maxlen)
            inMST[i] = false;

    // 开始找边
    for (int i = 0; i < num_e; i++){
        if (!inMST[i])
            continue;
        
        // 判断是否为关键边
        Djset dsc(n);
        int t = -1;
        for(int j = 0; j < num_e; j++){
            if (j == i || !inMST[j]) 
                continue;
            t = dsc.merge(ves[j].start, ves[j].end, ves[j].len);
            if (t != -1)
                break;
        }
         if (t > mstLen){
            res[0].emplace_back(ves[i].index);
            continue;
        }

        // 不是关键边时，判断是否伪关键边
        Djset dspc(n);
        dspc.merge(ves[i].start, ves[i].end, ves[i].len);
        for (int j = 0; j < num_e; j++){
            if (!inMST[j]) 
                continue;
            t = dspc.merge(ves[j].start, ves[j].end, ves[j].len);
            if (t != -1)
                break;
        }
        if (t== mstLen)
            res[1].emplace_back(ves[i].index);
    }
    return res;
}


