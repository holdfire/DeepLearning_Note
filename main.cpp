#include <iostream>
using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    int age = 10;
    const int* a = &age;
    age = 20;
    cout<<a;
    return 0;
}