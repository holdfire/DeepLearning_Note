// (1)构造一个并查集，
// (2)多余的边数 - 连通图的数目 + 1

class Djset{
public:
    vector<int> parent;
    vector<int> rank;
    int size;             // 记录连通图的数目；
    int rest;             // 记录所有的连通图多的边的数目

    Djset(int n): parent(n), rank(n), size(n), rest(0){
        for (int i = 0; i  < n; i++)
            parent[i] = i;
    }

    int find(int x){
        if (x != parent[x])
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void merge(int x, int y){
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty){
            if (rank[rootx] < rank[rooty])
                swap(rootx, rooty);
            parent[rooty] = rootx;
            if (rank[rootx]== rank[rooty])
                rank[rootx] += 1;
            size--;           
        }
        else{
            rest++;
        }
    };
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int res;
        Djset ds(n);
        int edges = connections.size();
        for (int i = 0; i < edges; i++){
            ds.merge(connections[i][0], connections[i][1]);
        }
        res = ds.rest - ds.size + 1;
        // return ds.rest;
        return (res < 0 ? -1 : ds.size-1);
    }
};