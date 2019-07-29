#include <iostream>
using namespace std;
#define MAX_VERTEX 30

int num;
int map[MAX_VERTEX] [MAX_VERTEX];
int visit[MAX_VERTEX];
int queue[MAX_VERTEX];
int rear, front;
/*
 수빈이는 동생과 숨바꼭질을 하고 있다. 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다. 수빈이는 걷거나 순간이동을 할 수 있다. 만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.
 
 수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.
 */



/*
 입력
 8 1 // 정점의 개수, 시작 정점
 1 2 // 정점 간 연결 관계. 1과 2가 연결
 1 3
 2 4
 2 5
 4 8
 5 8
 3 6
 3 7
 6 8
 7 8
 -1 -1 // 입력 끝
 */
void bfs(int vertex) {
    visit[vertex] = 1;//이제 이 위치는 방문한 것으로 판단.
    
    cout<<vertex;//해당 위치를 출력.
    
    queue[rear++] = vertex;//큐에다가 추가: 큐는 원소가 추가될 때 rear를 ++, 삭제될 때 front를 ++한다.
    
    while(front <rear) {//큐가 비어있지 않을 경우에 한해서
        vertex = queue[front++];
        for(int i=1; i<=num; i++) {
            if(map[vertex][i] == 1 && !visit[i]) {//갈 수 있는 경로이면서, 방문하지 않은 vertex
                visit[i] = 1;//그렇다면 방문.
                cout<<i;//방문한 위치 출력
                queue[rear++] = i;//큐에다가 추가
            }
        }
    }
    
}

int main(void) {
    
    int i,j;
    int start;
    int v1, v2;
    
    
    //초기화
    for (i = 0; i < MAX_VERTEX; i++) {
        for (j = 0; j < MAX_VERTEX; j++) {
            map[i][j] = 0;
        }
        visit[i] = 0;//너비 우선이므로, 방문한 너비의 행 방문 여부만 확인하면 된다
        queue[i] = 0;
    }
    front = 0;
    rear = 0;
    
    scanf("%d %d", &num, &start); //정점의 개수, 시작 정점(일반적으로 1)
    
    while (true) {
        scanf("%d %d", &v1, &v2);
        if (v1 == -1 && v2 == -1) {
            break;
        }
        map[v1][v2] = map[v2][v1] = 1;//정점 간의 관계가 있으면 1로 덮어쓰기
    }
    
    for(int k=0; k<num; k++) {
        for(int h=0; h<num; h++) {
            cout <<map[k][h];
        }
        cout<<"여기까지가"<<k<<"행"<<endl;
    }
    
    bfs(start);
    cout<<endl;
    }
