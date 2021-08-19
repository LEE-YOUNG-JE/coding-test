#include<iostream>
#include <vector>
using namespace std;
int main(void){
    vector<int> v;
    v.push_back(2);
    v.push_back(2);
    v.push_back(2);
    v.push_back(2);
    v.push_back(2);
    cout << v.size() << endl;

    cout << (1<<v.size()) << endl;
}