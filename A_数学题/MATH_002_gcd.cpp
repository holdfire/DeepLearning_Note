// 求两个正整数p和q的最大公约数
// 递归求解：减而治之
# include <cstdlib>
# include <iostream>

using namespace std;

// Greatest Common Divisor
int gcd(int p, int q){
    if (p == 0)
        return q;
    else if (q == 0)
        return p;
    else if (p >= q)
        return gcd(p-q, q);
    return gcd(p, q-p);
}


int main(){
    int max_value = 100;
    for(int i=0; i < 10; i++){
        int p = rand() % max_value;
        int q = rand() % max_value;
        int res = gcd(p, q);
        cout<<"p: "<<p<<" q: "<<q<<" res: "<<res<<endl;
    }
    return 0;
}