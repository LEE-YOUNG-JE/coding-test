#include <string>
#include <vector>
#define HEIGHT_MAX 5000 / 4 + 1;
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int sum = brown + yellow;
    int width;
    int height;
    int height_max = HEIGHT_MAX;
    for(height = 3; height <= height_max; height++){
        if(sum % height == 0){
            width = sum / height;
            if((width-2) * (height-2)==yellow){
                answer.push_back(width);
                answer.push_back(height);
                break;
            }              
        }
    }
    return answer;
}