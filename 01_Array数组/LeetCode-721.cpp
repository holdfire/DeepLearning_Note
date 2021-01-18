
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
// #include <functional>

using namespace std;

class UnionSet{
public:
    vector<int> parent;      // 记录节点的根
    vector<int> rank;        // 记录根节点的深度，用于优化
    UnionSet(int n): parent(vector<int>()n), rank(vector<int>(n)){
        for (int i = 0; i < n; i++)
        parent[i] = i;
    }

    int find(int x){
        // 压缩方式：直接指向根节点
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
            if (rank[rootx] == rank[rooty])
                rank[rootx] += 1;
        }
    }
}





vector<vector<string> > accountsMerge(vector<vector<string> >& accounts) {
    // res用来存储结果
    vector<vector<string> > res;
    // 使用hash[string] = i的字典，key为邮箱地址，value为res中的索引；
    unordered_map<string, int> hash;
    int n = accounts.size();
    UnionSet ds(n);
    
    

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
