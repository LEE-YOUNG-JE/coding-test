#include <string>
#include <vector>
#include <iostream>
using namespace std;
string left(string a){
    string temp(a);
    temp[5] = a[1];
    temp[3] = a[5];
    temp[4] = a[3];
    temp[1] = a[4];
    return temp;
}
string top(string a){
    string temp(a);
    temp[5] = a[0];
    temp[2] = a[5];
    temp[4] = a[2];
    temp[0] = a[4];
    return temp;
}
vector<int> solution(vector<vector<string>> queries) {
    vector<int> answer;
    string temp;
    for(int k= 0; k < queries.size(); k++){
        for(int j = 0; queries[k].size(); j++){
            for(int i = 0; i < 4; i++){
                temp = left(queries[k][j]);
                if(queries[0][1] == temp){
                    answer.push_back(1);
                    break;
                }
            }
        }
    }



    return answer;
}