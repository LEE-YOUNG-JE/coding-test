#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end(), greater<int>());
    long long max_times =  (long long)times[0]*n ;///lonlong 남의 코드참조
    long long min_times = 0;
    long long mid_times;
    long long people_check = 0;
    while(min_times < max_times){
        people_check = 0;
        mid_times = (max_times + min_times) / 2;
        for(int at : times){
        people_check += mid_times / at;
        }
        if(people_check >= n) {
            max_times = mid_times;    
        }
        else if(people_check < n) {
            min_times = mid_times + 1;          
        }
    }
    answer = min_times;
    
    return answer;
    
    
}