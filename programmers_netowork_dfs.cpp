#include <string>
#include <vector>
using namespace std;

vector<vector<int>> computers_all;
vector<int> check;
int network_number = 0;
int N;

void dfs(int i){   
    check[i] = 1;
    for(int j = 0; j < N; j++){        
        if(computers_all[i][j] == 1 && check[j]!=1) {
            dfs(j);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    N = n;
    vector<int> zero(n,0);
    
    check.resize(n,0);
    
    for(int i=0; i < n; i++){
        computers_all.push_back(zero);
    }
    
    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++){
            if(i!=j && computers[i][j] == 1){
                computers_all[i][j] = 1;
                computers_all[j][i] = 1;
            }
        }
    }
    
    for(int i=0; i < n; i++){
        if(check[i]==0){
            dfs(i);
            network_number++;
        } 
    }
    answer = network_number;
    return answer;
}