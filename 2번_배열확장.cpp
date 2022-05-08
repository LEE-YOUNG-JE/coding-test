#include <string>
#include <vector>

using namespace std;
/*vector<vector<int>> m_square;
void repeat(vector<vector<int>> square, int k){
vector<vector<int>> v1 = {{1,2,3}, {4,5,6}};
    vector<vector<int>> v2 = {{7,8,9}, {10,11,12}};
    //v1.resize(4);
    v1.push_back(v2[0]);
    answer = v1;
}*/

vector<vector<int>> solution(vector<vector<int>> square, int k) {
    vector<vector<int>> answer;

    for(int i = 0; i < k; i++){
        for(int k = 0; k < square.size(); k++){ //y축 복사
            for(int j = square[k].size()-1; j>=0; j--){ //1번 확장하는 반복문
                square[k].push_back(square[k][j]);
            }
        }

        for(int k = square.size()-1; k >= 0; k--){
            square.push_back(square[k]);
        }

    }
    answer = square;
    return answer;
}