#include <string>
#include <vector>
#include <queue>
#define MAX 200
using namespace std;

int check[MAX]={0}; // 확인한 노드인지 체크, 전역변수로 선언해서 공유, 0으로 초기화
int network_number =1; //몇번째 네트워크인지 체크하는 변수(ex 1,2는 network 1, 3은 network 2)
queue<int> q; //queue를 선언해서 가로 1행씩 수행하도록 알고리즘 구현

int N;
vector<vector<int>> computers_all; //computers를 전역변수로 사용해서 매개변수로 안넘겨도됨

void bfs(){   
    if(!q.empty()){ //queue에 무언가가 있다면
        for(int i=0; i < q.size(); i++){ //q에 있는 개수만큼만 반복한다. 왜냐하면 1행씩 계산위해
        int front = q.front(); //앞에거 읽고
        check[front]=network_number; // 읽었으니까 check에 몇번째 네트워크인지 입력       
        q.pop();//할일 했으므로 pop
            for(int i=0; i < N; i++){ //방금 전 pop한 노드에서 연결된 무언가가 있을 수 있으므로
                if(front!=i && computers_all[front][i] == 1 && check[i]==0) q.push(i); 
            }   //pop한 front랑 연결된(check안된) 노드가 있다면 새로운 행에 있는 것이므로 push
        }
    }
        
    if(q.empty()){//비어있다면 더이상 연결된 네트워크가 없다는 뜻이므로
        network_number+=1; //다음 네트워크를 세기위해 1더해주고 함수 마무리
        return;
    }
    bfs();// 비어있지않아서 위의 if가 실행안되면 재귀해서 계속 queue에 추가하고 없어질때까지 반복
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    N =n; //전역변수에 값 저장해서 매개변수로 안줘도됨
    
    for(int i=0; i<n; i++){//전역변수 computers_all을 computers와 같게하기 위한 작업
        vector<int> temp; 
        for(int j=0; j<n; j++){
            temp.push_back(computers[i][j]);
        }
         computers_all.push_back(temp);
    }
    
    for(int i=0; i < n; i++){//모든 노드를 방문하는데
        if(check[i]==0){ //이미 방문됐다면 패스, 방문안된것만 방문한다
            check[i]=network_number;//방문해서 방문표시 해주고
            for(int j=0; j<n; j++){//방문한 노드가 새롭게 연결된 노드가 있는지 확인
              if(i!=j && computers_all[i][j] == 1 && check[j]==0) q.push(j);     
            }//있으면 queue에 push해줘서 다음 행 대비
            bfs();//bfs 실행하고 계속 queue가 없을 때까지 재귀해서 네트워크 나눔
         }        
    }
    
    answer = network_number-1; //마지막에 network_number가 추가돼서 나오므로 1빼줌
    return answer;
}
