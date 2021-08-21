#include<iostream>
#include <string>
#include <vector>
//int size;
using namespace std;

//int max=0;
void dfs(vector<vector<int>> &triangle, int row, int column, int sum, int size, int* max){
    if(row == size-1){
        if(*max < sum){
            *max = sum;
            return;
        }
    }
    dfs(triangle, row + 1, column, sum + triangle[row+1][column], size, max);
    dfs(triangle, row + 1, column + 1, sum + triangle[row+1][column + 1], size, max);
}

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int size = triangle.size();
    int* max = 0;
    dfs(triangle, 0, 0, triangle[0][0], size, max);
    answer = *max;
    return answer;
}

int main(){
    int ans=0;
    vector<vector<int>> a = {{7}, {3,8}, {8,1,0}, {2,7,4,4}, {4,5,2,6,5}};
    ans = solution(a);
    cout << ans << endl;
}