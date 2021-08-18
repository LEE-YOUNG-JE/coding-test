#include <string>
#include <vector>

using namespace std;
vector<int> nums;
int check=0;
void dfs(int target, int sum, int x){
    if(x==nums.size()){
        if(target==sum){
            check++;
            return;
        }
        else return;
    } 
   
    dfs(target, sum+nums[x], x+1);
    dfs(target, sum-nums[x], x+1);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int x = 0;
    nums = numbers;
    int size = numbers.size();
    dfs(target, 0, x);
    answer = check;
    return answer;
}