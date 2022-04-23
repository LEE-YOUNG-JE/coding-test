#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n, int k, vector<int> floors) {
    vector<int> count(floors.size(), 0);
    vector<int> answer(floors.size(), 0);
    for(int i = 0 ; i < floors.size(); i++){
        int m_floor = floors[i];
        if(count[m_floor-1] < k) {
            count[m_floor-1] += 1;
            answer[i] = m_floor;
        }
        else{
            int bottom = 1;
            bool bottom_success = false;
            int top = 1;
            bool top_success = false;

            for(int j = m_floor-1; j >= 1; j--){
                if(count[j-1] < k){
                    bottom_success = true;
                    break;
                }
                else bottom += 1;
            }
            for(int j = m_floor+1; j <= n; j++){
                if(count[j-1] < k){
                    top_success = true;
                    break;
                }
                else top += 1;
            }
            if(bottom_success == true && top_success == true){
                if(bottom <= top) {
                    count[m_floor - bottom-1] += 1;
                    answer[i] = m_floor - bottom;
                }
                else {
                    count[m_floor + top-1] += 1;
                    answer[i] = m_floor + top;
                }
            }
            else if(bottom_success == true && top_success == false){
                count[m_floor - bottom-1] += 1;
                answer[i] = m_floor - bottom;
            }

            else if(bottom_success == false && top_success == true){
                count[m_floor + top-1] += 1;
                answer[i] = m_floor + top;
            }

            //else break;
        }
    }

    return answer;
}