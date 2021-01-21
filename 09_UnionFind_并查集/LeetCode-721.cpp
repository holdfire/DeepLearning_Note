// Reference: https://leetcode-cn.com/problems/accounts-merge/solution/tu-jie-yi-ran-shi-bing-cha-ji-by-yexiso-5ncf/
// 解题思路：
// (1) 构造并查集：初始的元素是每个vector的索引
// (2) 合并并查集：合并有共同邮件的，此时需要一个哈希表来记录；
// (3) 遍历并查集：把各个不相交的集合放到结果vector中

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;


// Union Find Disjoint Set: 并查集元素保存的是索引
class Djset{
public:
    vector<int> parent;
    vector<int> rank;

    // 使用了初始化列表的构造函数
    Djset(int n): parent(vector<int>(n)), rank(vector<int>(n)){
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    // 查找时使用路径压缩
    int find(int x){
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    // 合并操作
    void merge(int x, int y){
        int rootx = find(x);
        int rooty = find(y);
        if (rootx == rooty)
            return;
        if (rank[rootx] < rank[rooty])
            swap(rootx, rooty);
        parent[rooty] = rootx;
        if (rank[rootx] == rank[rooty])
            rank[rootx] += 1;
    }
};



vector<vector<string> > accountsMerge(vector<vector<string> >& accounts) {
    // res用来存储结果
    vector<vector<string> > res;
    // 使用hash[string] = i的字典，key为邮箱地址，value为res中的索引；
    unordered_map<string, int> hash;
    int n = accounts.size();
    // 构造并查集
    Djset ds(n);

    // 合并并查集
    for(int i = 0; i < accounts.size(); i++){
        for (int j = 1; j < accounts[i].size(); j++){
            if (hash.find(accounts[i][j]) != hash.end())
                ds.merge(i, hash[accounts[i][j]]);
            hash[accounts[i][j]] = i;
        }
    }

    // 遍历并查集，用一个哈希表把并查集不相交的部分分别存储；
    unordered_map<int, vector<string> > dict;
    for (auto& [k, v]: hash)
        dict[ds.find(v)].push_back(k);

    // 处理上述哈希表，排序+插入
    for (auto& [k, v]: dict){
        sort(v.begin(), v.end());
        vector<string> tmp(1, accounts[k][0]);
        tmp.insert(tmp.end(), v.begin(), v.end());
        res.push_back(tmp);
    }
    return res;
}



int main(){

    vector<vector<string> > test;

    std::vector<std::string> a1;
    std::string a11("Alex");
    std::string a12("Alex5@m.co");
    std::string a13("Alex4@m.co");
    std::string a14("Alex0@m.co");
    a1.push_back(a11);
    a1.push_back(a12);
    a1.push_back(a13);
    a1.push_back(a14);

    vector<string> a2;
    std::string a21("Ethan");
    std::string a22("Ethan3@m.co");
    std::string a23("Ethan0@m.co");
    a2.push_back(a21);
    a2.push_back(a22);
    a2.push_back(a22);
    a2.push_back(a23);
    

    vector<string> a3;
    std::string a31("Kevin");
    std::string a32("Kevin4@m.co");
    std::string a33("Kevin2@m.co");
    a3.push_back(a31);
    a3.push_back(a32);
    a3.push_back(a33);
    a3.push_back(a33);
    

    vector<string> a4;
    std::string a41("Gabe");
    std::string a42("Gabe0@m.co");
    std::string a43("Gabe3@m.co");
    std::string a44("Gabe2@m.co");
    a4.push_back(a41);
    a4.push_back(a42);
    a4.push_back(a43);
    a4.push_back(a44);

    vector<string> a5;
    std::string a51("Gabe");
    std::string a52("Gabe3@m.co");
    std::string a53("Gabe4@m.co");
    std::string a54("Gabe2@m.co");
    a5.push_back(a51);
    a5.push_back(a52);
    a5.push_back(a53);
    a5.push_back(a54);
    

    test.push_back(a1);
    test.push_back(a2);
    test.push_back(a3);
    test.push_back(a4);
    test.push_back(a5);

    for (int i=0; i < test.size(); i++){
        for (int j = 0; j<test[i].size(); j++)
            cout<<test[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;


    vector<vector<string> > res;
    res = accountsMerge(test);
    for (int i=0; i < res.size(); i++){
        for (int j = 0; j<res[i].size(); j++)
            cout<<res[i][j]<<" ";
        cout<<endl;
    }

    
    return 0;
}
