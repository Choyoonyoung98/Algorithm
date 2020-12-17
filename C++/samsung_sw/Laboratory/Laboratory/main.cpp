#include <iostream>
#include <queue>
#define MAX_SIZE 9
#define WALL 3

using namespace std;
//무언가 기존 배열을 건드리거나 삽입하거나 수정할 때는 복사본을 만들어서 실행시킨다.

int N = 0;
int M = 0;
int lab[MAX_SIZE][MAX_SIZE] = {0};
int cpy_lab[MAX_SIZE][MAX_SIZE] = {0};
int answer = 0;
queue<pair<int, int>> virus;
struct Dir{
    int y;
    int x;
};

Dir moveDir[4] = {{-1,0},{1,0},{0,-1},{0,1}};
void BFS() {
    int afterSpread[MAX_SIZE][MAX_SIZE];
    int virusX = 0;
    int virusY = 0;
    int nextY = 0;
    int nextX = 0;
    
    for(int i=0; i<M; i++) {
        for(int j=0; j<N; j++) {
            afterSpread[i][j] = cpy_lab[i][j];
            
            if(afterSpread[i][j] == 2) virus.push({i,j});
        }
    }
    
    
    while(!virus.empty()) {
        virusY = virus.front().first;
        virusX = virus.front().second;
        virus.pop();
        
        for(int i=0; i<4; i++) {
            nextY = virusY + moveDir[i].y;
            nextX = virusX + moveDir[i].x;
            
            if(0<=nextY && nextY <=N && 0<=nextX && nextX <=M && afterSpread[nextY][nextX] == 0) {
                afterSpread[nextY][nextX] = 2;
                virus.push({nextY, nextX});
                
            }
        }
        
    }
    
    int empty = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(afterSpread[i][j] == 0) empty++;
        }
    }
    
    answer = max(answer, empty);
    
}
void makeWall(int wall) {
    if(wall == 3) {
        BFS();
        return;
    }
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(cpy_lab[i][j] == 0) {
                cpy_lab[i][j] = 1;
                makeWall(wall+1);
                cpy_lab[i][j] = 0;
            }
        }
    }
}

int main() {
    cin>>N>>M;
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin>>lab[i][j];
        }
    }
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(lab[i][j] == 0) {
                for(int k=0; k<N; k++) {
                    for(int h=0; h<M; h++) {
                        cpy_lab[k][h] = lab[k][h];
                    }
                }
                cpy_lab[i][j] = 1;
                makeWall(1);
                cpy_lab[i][j] = 0;
            }
        }
    }
    
    cout<<answer;
    return 0;
    
}
