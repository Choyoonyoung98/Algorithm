#include <iostream>
#include<cstdio>
#include<queue>
using namespace std;
#define MAX_VERTEX 100

/*
 미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸을 나타낸다. 이러한 미로가 주어졌을 때, (1, 1)에서 출발하여 (N, M)의 위치로 이동할 때 지나야 하는 최소의 칸 수를 구하는 프로그램을 작성하시오. 한 칸에서 다른 칸으로 이동할 때, 서로 인접한 칸으로만 이동할 수 있다.
 
 위의 예에서는 15칸을 지나야 (N, M)의 위치로 이동할 수 있다. 칸을 셀 때에는 시작 위치와 도착 위치도 포함한다.
 */


int map[MAX_VERTEX] [MAX_VERTEX];//실제 미로값 boolean으로 담을 공간
int visit[MAX_VERTEX][MAX_VERTEX];//지나간 길을 등록하는 2차원 배열.

int row = 4;//4행 ---
int column=6;//6열 |

int direction[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};//down, up, right, left



//Input를 통한 초기화
void Input(){
    int data[4][6] = {{1,0,1,1,1,1},{1,0,1,0,1,0},{1,0,1,0,1,1},{1,1,1,0,1,1}};//주어질 데이터
    for(int i =0; i<4; i++) {
        for(int j=0; j<6; j++) {
            
            (data[i][j] == 1)?map[i][j]=1:map[i][j]=0;
            //실제 받아오는 데이터값이 1을 포함하고 있으면(갈 수 있는 길이면) map은 true, 아니면 false
            //cout<<map[i][j];//주어진 값 map[][]에 담기
            
        }
    }
    
}

void Print(int num) {
    cout<<"함수 호출";
    cout<<num<<endl;
}
//배열 안에 있는지 확인
bool isInside(int y, int x) {
    
    return (y >=0 && y<row)&&(x>=0 && x<column);
    //y의 값이 row의 범위 안에 있는지? x의 값이 column 범위 안에 있는지?
}

//너비 우선 검색
int bfs() {
    int x = 0;
    int y=0;
    
    queue<pair<int,int>> q;//queue for bfs search
    q.push(pair<int, int> (y,x));//<first,second>
    visit[y][x] = 1;//0,0에서 미로를 탈출하기 시작하므로 방문했음을 밝힘
    
    while(!q.empty()) {//큐가 비어있지 않았으면, 그런데 초기에는 비어있지 않겠지 당연히 방금 0,0 push 했잖아.
        y = q.front().first;//y:0
        x= q.front().second;//x:0
        
        q.pop();//0,0을 출력
        
        if((y == row-1) &&(x == column-1) )break;//도착지점에 도착하면 이 함수를 끝을 낸다.
        
        
        for(int i=0; i<4; i++) {
            //up, down,left,right를 모두 고려. 총 4가지 고려.
            int nextY = y + direction[i][0];
            int nextX = x+direction[i][1];
            //if i=0 (1,0), i=1 (-1,0), i=2 (0,1) i=3 (0,-1)
            
            
            //next y,x가 배열 내부에 있고, 방문된 적 없고, map이 1인 경우
            if(isInside(nextY, nextX) && visit[nextY][nextX]==0 && map[nextY][nextX]==1) {
                visit[nextY][nextX] = visit[y][x]+1;
                q.push(pair<int, int> (nextY,nextX));
                
            }
        }
    }
    for(int i=0; i<row; i++) {
        for(int j=0; j<column; j++) {
            cout <<visit[i][j];
        }
        cout<<endl;
    }
    return visit[row-1][column-1];
}
int main(void) {
    Input();
    Print(bfs());
    return 0;
}
